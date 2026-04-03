#pragma once

#include "OpacityAnimation.g.h"
#include "../Abstract/ImplicitAnimation{TValue,TKeyFrame}.h"
#include "../KeyFrames/ScalarKeyFrame.h"
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    using namespace winrt::Microsoft::UI::Xaml;

    struct OpacityAnimation;

    struct OpacityAnimationTraits
    {
        using owner_type = OpacityAnimation;
        using class_type = Animations::OpacityAnimation;
        using public_value_type = winrt::Windows::Foundation::IReference<double>;
        using parsed_value_type = double;
        using keyframe_impl_type = implementation::ScalarKeyFrame;
        using keyframe_type = Animations::ScalarKeyFrame;
        static std::optional<parsed_value_type> Parse(winrt::Windows::Foundation::IReference<double> const& value)
        {
            return value;
        }
    };

    /// <summary>
    /// An opacity animation working on the composition or layer.
    /// </summary>
    struct OpacityAnimation : OpacityAnimationT<OpacityAnimation, ImplicitAnimationBase<OpacityAnimationTraits>>
    {
        winrt::hstring ExplicitTarget() const noexcept
        {
            return L"Opacity";
        }
    };
}

namespace winrt::XamlToolkit::WinUI::Animations::factory_implementation
{
    struct OpacityAnimation : OpacityAnimationT<OpacityAnimation, implementation::OpacityAnimation> {};
}