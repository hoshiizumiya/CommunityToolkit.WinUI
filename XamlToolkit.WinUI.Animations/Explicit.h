#pragma once

#include "Explicit.g.h"
#include "Xaml/AnimationDictionary.h"
#include <winrt/Microsoft.UI.Xaml.h>
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    /// <summary>
    /// Attached properties to support explicitly triggered animations for UIElement instances.
    /// </summary>
    struct Explicit : ExplicitT<Explicit>
    {
    public:
        Explicit() = default;

        /// <summary>
        /// Gets the value of the AnimationsProperty property.
        /// </summary>
        static Animations::AnimationDictionary GetAnimations(winrt::Microsoft::UI::Xaml::UIElement const& element);

        /// <summary>
        /// Sets the value of the AnimationsProperty property.
        /// </summary>
        static void SetAnimations(winrt::Microsoft::UI::Xaml::UIElement const& element, Animations::AnimationDictionary const& value);

        /// <summary>
        /// Identifies the AnimationsProperty dependency property.
        /// </summary>
        static const wil::single_threaded_property<winrt::Microsoft::UI::Xaml::DependencyProperty> AnimationsProperty;

    private:
        static void OnAnimationsPropertyChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);
    };
}

namespace winrt::XamlToolkit::WinUI::Animations::factory_implementation
{
    struct Explicit : ExplicitT<Explicit, implementation::Explicit> {};
}
