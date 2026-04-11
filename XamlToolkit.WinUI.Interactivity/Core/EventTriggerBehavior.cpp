#include "pch.h"
#include "EventTriggerBehavior.h"
#include "EventManager.h"
#include "../ActionCollection.h"
#include "../Interaction.h"
#if __has_include("EventTriggerBehavior.g.cpp")
#include "EventTriggerBehavior.g.cpp"
#endif

namespace winrt::XamlToolkit::WinUI::Interactivity::implementation
{
    const wil::single_threaded_property<winrt::DependencyProperty> EventTriggerBehavior::EventNameProperty = winrt::DependencyProperty::Register(
        L"EventName",
        winrt::xaml_typename<winrt::hstring>(),
        winrt::xaml_typename<class_type>(),
        PropertyMetadata(winrt::box_value(L"Loaded"), &EventTriggerBehavior::OnEventNameChanged));

    const wil::single_threaded_property<winrt::DependencyProperty> EventTriggerBehavior::SourceObjectProperty = winrt::DependencyProperty::Register(
        L"SourceObject",
        winrt::xaml_typename<winrt::IInspectable>(),
        winrt::xaml_typename<class_type>(),
        PropertyMetadata(nullptr, &EventTriggerBehavior::OnSourceObjectChanged));

    winrt::hstring EventTriggerBehavior::EventName() const
    {
        return winrt::unbox_value<winrt::hstring>(GetValue(EventNameProperty()));
    }

    void EventTriggerBehavior::EventName(winrt::hstring const& value)
    {
        SetValue(EventNameProperty(), winrt::box_value(value));
    }

    winrt::IInspectable EventTriggerBehavior::SourceObject() const
    {
        return GetValue(SourceObjectProperty());
    }

    void EventTriggerBehavior::SourceObject(winrt::IInspectable const& value)
    {
        SetValue(SourceObjectProperty(), value);
    }

    void EventTriggerBehavior::OnAttached()
    {
        SetResolvedSource(ComputeResolvedSource());
    }

    void EventTriggerBehavior::OnDetaching()
    {
        SetResolvedSource(nullptr);
    }

    void EventTriggerBehavior::SetResolvedSource(winrt::IInspectable const& newSource)
    {
        if (AssociatedObject() == nullptr || _resolvedSource == newSource)
        {
            return;
        }

        if (_resolvedSource != nullptr)
        {
            UnregisterEvent(EventName());
        }

        _resolvedSource = newSource;

        if (_resolvedSource != nullptr)
        {
            RegisterEvent(EventName());
        }
    }

    winrt::IInspectable EventTriggerBehavior::ComputeResolvedSource()
    {
        if (ReadLocalValue(EventTriggerBehavior::SourceObjectProperty()) != DependencyProperty::UnsetValue())
        {
            return SourceObject();
        }

        return AssociatedObject();
    }

    void EventTriggerBehavior::RegisterEvent(winrt::hstring const& eventName)
    {
        if (eventName.empty() || _resolvedSource == nullptr)
        {
            return;
        }

        if (eventName == L"Loaded")
        {
            if (auto element = _resolvedSource.try_as<FrameworkElement>())
            {
                if (!IsElementLoaded(element))
                {
                    _eventToken = element.Loaded({ this, &EventTriggerBehavior::OnEvent });
                    _isRegistered = true;
                }
            }

            return;
        }

        _eventToken = EventManager::Register(eventName, _resolvedSource, [this](winrt::IInspectable const& eventArgs) { OnEvent(_resolvedSource, eventArgs); });
        _isRegistered = true;
    }

    void EventTriggerBehavior::UnregisterEvent(winrt::hstring const& eventName)
    {
        if (!_isRegistered || eventName.empty() || _resolvedSource == nullptr)
        {
            return;
        }

        if (eventName == L"Loaded")
        {
            if (auto element = _resolvedSource.try_as<FrameworkElement>())
            {
                element.Loaded(_eventToken);
            }
        }
        else
        {
            EventManager::Unregister(eventName, _resolvedSource, _eventToken);
        }

        _eventToken = {};
        _isRegistered = false;
    }

    void EventTriggerBehavior::OnEvent([[maybe_unused]] winrt::IInspectable const& sender, winrt::IInspectable const& eventArgs)
    {
        auto actions = Actions();
        Interaction::ExecuteActions(_resolvedSource, actions, eventArgs);
    }

    void EventTriggerBehavior::OnSourceObjectChanged(DependencyObject const& dependencyObject, [[maybe_unused]] DependencyPropertyChangedEventArgs const& args)
    {
        auto behavior = winrt::get_self<EventTriggerBehavior>(dependencyObject.as<class_type>());
        behavior->SetResolvedSource(behavior->ComputeResolvedSource());
    }

    void EventTriggerBehavior::OnEventNameChanged(DependencyObject const& dependencyObject, DependencyPropertyChangedEventArgs const& args)
    {
        auto behavior = winrt::get_self<EventTriggerBehavior>(dependencyObject.as<class_type>());
        if (behavior->AssociatedObject() == nullptr || behavior->_resolvedSource == nullptr)
        {
            return;
        }

        auto oldEventName = winrt::unbox_value_or<winrt::hstring>(args.OldValue(), L"");
        auto newEventName = winrt::unbox_value_or<winrt::hstring>(args.NewValue(), L"");

        behavior->UnregisterEvent(oldEventName);
        behavior->RegisterEvent(newEventName);
    }

    bool EventTriggerBehavior::IsElementLoaded(FrameworkElement const& element)
    {
        if (element == nullptr)
        {
            return false;
        }

        UIElement rootVisual{ nullptr };
        if (auto xamlRoot = element.XamlRoot())
        {
            rootVisual = xamlRoot.Content();
        }

        DependencyObject parent = element.Parent();
        if (parent == nullptr)
        {
            parent = VisualTreeHelper::GetParent(element);
        }

        return (parent != nullptr || (rootVisual != nullptr && element == rootVisual));
    }
}

