#pragma once

#include "StopAnimationActivity.g.h"
#include "Activity.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    struct StopAnimationActivity : StopAnimationActivityT<StopAnimationActivity, Activity>
    {
    public:
        StopAnimationActivity() = default;

        Animations::AnimationSet Animation() const
        {
            return GetValue(AnimationProperty).try_as<Animations::AnimationSet>();
        }
        void Animation(Animations::AnimationSet const& value)
        {
            SetValue(AnimationProperty, winrt::box_value(value));
        }

        winrt::Microsoft::UI::Xaml::UIElement TargetObject() const
        {
            return GetValue(TargetObjectProperty).try_as<Microsoft::UI::Xaml::UIElement>();
        }
        void TargetObject(Microsoft::UI::Xaml::UIElement const& value)
        {
            SetValue(TargetObjectProperty, winrt::box_value(value));
        }

        winrt::Windows::Foundation::IAsyncAction InvokeAsync(winrt::Microsoft::UI::Xaml::UIElement const& element) override;

        static const wil::single_threaded_property<winrt::Microsoft::UI::Xaml::DependencyProperty> AnimationProperty;
        static const wil::single_threaded_property<winrt::Microsoft::UI::Xaml::DependencyProperty> TargetObjectProperty;
    };
}

namespace winrt::XamlToolkit::WinUI::Animations::factory_implementation
{
    struct StopAnimationActivity : StopAnimationActivityT<StopAnimationActivity, implementation::StopAnimationActivity> {};
}
