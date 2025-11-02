#pragma once

#include "StyleExtensionResourceDictionary.g.h"
#include <winrt/Microsoft.UI.Xaml.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
	struct StyleExtensionResourceDictionary : StyleExtensionResourceDictionaryT<StyleExtensionResourceDictionary>
	{
		StyleExtensionResourceDictionary() = default;
	};
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
	struct StyleExtensionResourceDictionary : StyleExtensionResourceDictionaryT<StyleExtensionResourceDictionary, implementation::StyleExtensionResourceDictionary>
	{
	};
}
