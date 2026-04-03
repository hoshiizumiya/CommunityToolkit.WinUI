#pragma once

#include "ScaleAnimation.g.h"
#include "../Abstract/ImplicitAnimation{TValue,TKeyFrame}.h"
#include "../KeyFrames/Vector3KeyFrame.h"
#include "../Extensions/AnimationExtensions.h"
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.Numerics.h>
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    using namespace winrt::Microsoft::UI::Xaml;
    using namespace winrt::Windows::Foundation::Numerics;

    struct ScaleAnimation;

    struct ScaleAnimationTraits
    {
        using owner_type = ScaleAnimation;
        using class_type = Animations::ScaleAnimation;
        using public_value_type = winrt::hstring;
        using parsed_value_type = winrt::Windows::Foundation::Numerics::float3;
        using keyframe_impl_type = implementation::Vector3KeyFrame;
        using keyframe_type = Animations::Vector3KeyFrame;
        static std::optional<parsed_value_type> Parse(winrt::hstring const& value)
        {
            if (value.empty())
            {
                return std::nullopt;
            }

            return Animations::AnimationExtensions::ToVector3(value);
        }
    };

    struct ScaleAnimation : ScaleAnimationT<ScaleAnimation, ImplicitAnimationBase<ScaleAnimationTraits>>
    {
        winrt::hstring ExplicitTarget() const noexcept
        {
            return L"Scale";
        }
    };
}

namespace winrt::XamlToolkit::WinUI::Animations::factory_implementation
{
    struct ScaleAnimation : ScaleAnimationT<ScaleAnimation, implementation::ScaleAnimation> {};
}