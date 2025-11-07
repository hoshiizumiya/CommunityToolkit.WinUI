#pragma once

#include <winrt/Microsoft.UI.Text.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
	struct RichSuggestQuery
	{
		RichSuggestQuery() = default;

		std::optional<winrt::hstring> Prefix;

		std::optional<winrt::hstring> QueryText;

		Microsoft::UI::Text::ITextRange Range{ nullptr };

		winrt::Windows::Foundation::IAsyncAction Task { nullptr };
	};
}