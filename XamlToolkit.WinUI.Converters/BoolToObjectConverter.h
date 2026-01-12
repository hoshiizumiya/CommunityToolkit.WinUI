#pragma once

#include "BoolToObjectConverter.g.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Converters::implementation
{
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI;
    using namespace winrt::Microsoft::UI;
    using namespace winrt::Microsoft::UI::Xaml;
    using namespace winrt::Microsoft::UI::Xaml::Media;
    using namespace winrt::Windows::UI::Xaml::Interop;

    struct BoolToObjectConverter : BoolToObjectConverterT<BoolToObjectConverter>
    {
        BoolToObjectConverter() = default;

        IInspectable TrueValue() const;
        void TrueValue(IInspectable const& value);

        IInspectable FalseValue() const;
        void FalseValue(IInspectable const& value);

        static const wil::single_threaded_property<DependencyProperty>  TrueValueProperty;
        static const wil::single_threaded_property<DependencyProperty>  FalseValueProperty;

        IInspectable Convert(IInspectable const& value, TypeName targetType, IInspectable const& parameter, winrt::hstring const& language) const;

        IInspectable ConvertBack(IInspectable const& value, TypeName targetType, IInspectable const& parameter, winrt::hstring const& language) const;
    };
}

namespace winrt::XamlToolkit::WinUI::Converters::factory_implementation
{
    struct BoolToObjectConverter : BoolToObjectConverterT<BoolToObjectConverter, implementation::BoolToObjectConverter>
    {
    };
}
