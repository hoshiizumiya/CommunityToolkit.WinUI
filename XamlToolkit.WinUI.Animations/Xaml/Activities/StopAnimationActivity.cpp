#include "pch.h"
#include "StopAnimationActivity.h"
#if __has_include("StopAnimationActivity.g.cpp")
#include "StopAnimationActivity.g.cpp"
#endif

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    using namespace winrt::Microsoft::UI::Xaml;

    const wil::single_threaded_property<DependencyProperty> StopAnimationActivity::AnimationProperty =
        DependencyProperty::Register(
            L"Animation",
            winrt::xaml_typename<Animations::AnimationSet>(),
            winrt::xaml_typename<class_type>(),
            nullptr);

    const wil::single_threaded_property<DependencyProperty> StopAnimationActivity::TargetObjectProperty =
        DependencyProperty::Register(
            L"TargetObject",
            winrt::xaml_typename<UIElement>(),
            winrt::xaml_typename<class_type>(),
            nullptr);

    winrt::Windows::Foundation::IAsyncAction StopAnimationActivity::InvokeAsync(UIElement const& element)
    {
        auto animation = Animation();
        if (!animation)
        {
            throw winrt::hresult_error(E_INVALIDARG, L"Animation cannot be null.");
        }

        co_await Activity::InvokeAsync(element);

        if (const auto targetObject = TargetObject())
        {
            animation.Stop(targetObject);
        }
        else
        {
            animation.Stop(element);
        }
    }
}
