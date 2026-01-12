#pragma once

#include "BoolToVisibilityConverter.g.h"
#include "BoolToObjectConverter.h"

namespace winrt::XamlToolkit::WinUI::Converters::implementation
{
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI;
    using namespace winrt::Microsoft::UI;
    using namespace winrt::Microsoft::UI::Xaml;
    using namespace winrt::Microsoft::UI::Xaml::Media;
    using namespace winrt::Windows::UI::Xaml::Interop;

    struct BoolToVisibilityConverter : BoolToVisibilityConverterT<BoolToVisibilityConverter, BoolToObjectConverter>
    {
        BoolToVisibilityConverter()
        {
            TrueValue(winrt::box_value(Visibility::Visible));
            FalseValue(winrt::box_value(Visibility::Collapsed));
        }
    };
}

namespace winrt::XamlToolkit::WinUI::Converters::factory_implementation
{
    struct BoolToVisibilityConverter : BoolToVisibilityConverterT<BoolToVisibilityConverter, implementation::BoolToVisibilityConverter>
    {
    };
}
