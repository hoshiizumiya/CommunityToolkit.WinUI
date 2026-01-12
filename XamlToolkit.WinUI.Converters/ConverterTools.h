#pragma once

namespace winrt::XamlToolkit::WinUI::Converters::implementation
{
	using namespace winrt;
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::UI::Xaml::Interop;


	class ConverterTools
	{
	public:
		static bool TryParseBool(IInspectable const& parameter);

		static IInspectable Convert(IInspectable const& value, TypeName const& targetType);
	};
}
