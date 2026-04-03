#pragma once
#include "../../Builders/AnimationBuilder.h"
#include <winrt/Windows.Foundation.h>
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    using namespace winrt::Microsoft::UI::Composition;
    using namespace winrt::Microsoft::UI::Xaml;

    /// <summary>
    /// An interface representing a XAML model for a custom implicit composition animation.
    /// Mirrors the C# IImplicitTimeline shape for internal C++ wiring.
    /// </summary>
    class IImplicitTimeline
    {
    public:
        wil::untyped_event<winrt::Windows::Foundation::IInspectable> AnimationPropertyChanged;

        /// <summary>
        /// Gets a CompositionAnimation from the current node.
        /// </summary>
        virtual CompositionAnimation GetAnimation(UIElement const& element, winrt::hstring& target) = 0;

        virtual ~IImplicitTimeline() = default;
    };
}
