#pragma once

#include "AccentColorConverter.g.h"
#include <winrt/XamlToolkit.WinUI.Helpers.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::UI::Xaml::Interop;

    struct AccentColorConverter : AccentColorConverterT<AccentColorConverter>
    {
        AccentColorConverter() = default;

        static inline constexpr double ValueDelta = 0.1;

        static XamlToolkit::WinUI::HsvColor GetAccent(XamlToolkit::WinUI::HsvColor hsvColor, int accentStep);

        IInspectable Convert(IInspectable const& value, TypeName targetType, IInspectable const& parameter, winrt::hstring const& language);

        IInspectable ConvertBack(IInspectable const& value, TypeName targetType, IInspectable const& parameter, winrt::hstring const& language);
    };
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
    struct AccentColorConverter : AccentColorConverterT<AccentColorConverter, implementation::AccentColorConverter>
    {
    };
}
