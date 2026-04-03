#include "pch.h"
#include "StartAnimationActivity.h"
#if __has_include("StartAnimationActivity.g.cpp")
#include "StartAnimationActivity.g.cpp"
#endif

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    using namespace winrt::Microsoft::UI::Xaml;

    const wil::single_threaded_property<DependencyProperty> StartAnimationActivity::AnimationProperty =
        DependencyProperty::Register(
            L"Animation",
            winrt::xaml_typename<Animations::AnimationSet>(),
            winrt::xaml_typename<class_type>(),
            nullptr);

    winrt::Windows::Foundation::IAsyncAction StartAnimationActivity::InvokeAsync(UIElement const& element)
    {
        if (const auto animation = Animation())
        {
            co_await animation.StartAsync(element);
        }
    }
}
