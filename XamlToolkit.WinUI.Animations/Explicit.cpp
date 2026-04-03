#include "pch.h"
#include "Explicit.h"
#if __has_include("Explicit.g.cpp")
#include "Explicit.g.cpp"
#endif

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    using namespace winrt::Microsoft::UI::Xaml;

    const wil::single_threaded_property<DependencyProperty> Explicit::AnimationsProperty = DependencyProperty::RegisterAttached(
        L"Animations",
        winrt::xaml_typename<Animations::AnimationDictionary>(),
        winrt::xaml_typename<class_type>(),
        PropertyMetadata(nullptr, PropertyChangedCallback{ &Explicit::OnAnimationsPropertyChanged }));

    Animations::AnimationDictionary Explicit::GetAnimations(UIElement const& element)
    {
        auto value = element.GetValue(AnimationsProperty());
        if (auto collection = value.try_as<Animations::AnimationDictionary>())
        {
            return collection;
        }

        Animations::AnimationDictionary collection;
        element.SetValue(AnimationsProperty(), collection);
        return collection;
    }

    void Explicit::SetAnimations(UIElement const& element, Animations::AnimationDictionary const& value)
    {
        element.SetValue(AnimationsProperty(), value);
    }

    void Explicit::OnAnimationsPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const& e)
    {
        auto element = d.try_as<UIElement>();
        if (!element)
        {
            return;
        }

        if (auto oldDictionary = e.OldValue().try_as<Animations::AnimationDictionary>())
        {
            auto impl = winrt::get_self<Animations::implementation::AnimationDictionary>(oldDictionary);
            impl->Parent(nullptr);
        }

        if (auto newDictionary = e.NewValue().try_as<Animations::AnimationDictionary>())
        {
            auto impl = winrt::get_self<Animations::implementation::AnimationDictionary>(newDictionary);
            impl->Parent(element);
        }
    }
}
