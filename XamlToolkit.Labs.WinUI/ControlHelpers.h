#pragma once
#include <winrt/Windows.Foundation.Metadata.h>
#include <winrt/Windows.UI.Xaml.h>


namespace winrt::XamlToolkit::Labs::WinUI::implementation
{
	struct ControlHelpers
	{
		static bool IsXamlRootAvailable()
		{
			return Windows::Foundation::Metadata::ApiInformation::IsPropertyPresent(winrt::name_of<winrt::Windows::UI::Xaml::UIElement>(), L"XamlRoot");
		}
	};
}