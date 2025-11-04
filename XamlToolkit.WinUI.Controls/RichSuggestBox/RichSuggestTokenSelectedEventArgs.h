#pragma once

#include "RichSuggestTokenSelectedEventArgs.g.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
	struct RichSuggestTokenSelectedEventArgs : RichSuggestTokenSelectedEventArgsT<RichSuggestTokenSelectedEventArgs>
	{
		RichSuggestTokenSelectedEventArgs() = default;

		RichSuggestTokenSelectedEventArgs(winrt::XamlToolkit::WinUI::Controls::RichSuggestToken const& token, winrt::Microsoft::UI::Text::ITextRange const& range) : Token(token), Range(range){ }

		wil::single_threaded_rw_property<winrt::XamlToolkit::WinUI::Controls::RichSuggestToken> Token;

		wil::single_threaded_rw_property<winrt::Microsoft::UI::Text::ITextRange> Range;
	};
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
	struct RichSuggestTokenSelectedEventArgs : RichSuggestTokenSelectedEventArgsT<RichSuggestTokenSelectedEventArgs, implementation::RichSuggestTokenSelectedEventArgs>
	{
	};
}
