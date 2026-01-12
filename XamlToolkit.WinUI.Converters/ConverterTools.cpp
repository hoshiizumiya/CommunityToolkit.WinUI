#include "pch.h"
#include "ConverterTools.h"

using namespace winrt::Microsoft::UI::Xaml::Markup;

namespace winrt::XamlToolkit::WinUI::Converters::implementation
{
	bool ConverterTools::TryParseBool(IInspectable const& parameter)
	{
		auto parsed = false;

		if (parameter)
		{
			auto value = winrt::unbox_value_or(parameter, L"false");

			if (value == L"True" || value == L"1" || value == L"true" || value == L"TRUE")
			{
				parsed = true;
			}
		}

		return parsed;
	}

	IInspectable ConverterTools::Convert(IInspectable const& value, TypeName const& targetType)
	{
		auto type = TypeName{ winrt::get_class_name(value) };
		if (type == targetType)
		{
			return value;
		}

		return XamlBindingHelper::ConvertValue(targetType, value);
	}
}