#pragma once

#include "StartAnimationActivity.g.h"
#include "Activity.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    struct StartAnimationActivity : StartAnimationActivityT<StartAnimationActivity, Activity>
    {
    public:
        StartAnimationActivity() = default;

        Animations::AnimationSet Animation() const
        {
            return GetValue(AnimationProperty).try_as<Animations::AnimationSet>();
        }
        void Animation(Animations::AnimationSet const& value)
        {
            SetValue(AnimationProperty, winrt::box_value(value));
        }

        winrt::Windows::Foundation::IAsyncAction InvokeAsync(Microsoft::UI::Xaml::UIElement const& element) override;

        static const wil::single_threaded_property<Microsoft::UI::Xaml::DependencyProperty> AnimationProperty;
    };
}

namespace winrt::XamlToolkit::WinUI::Animations::factory_implementation
{
    struct StartAnimationActivity : StartAnimationActivityT<StartAnimationActivity, implementation::StartAnimationActivity> {};
}
