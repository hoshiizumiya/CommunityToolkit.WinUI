#pragma once

#include "SuggestionRequestedEventArgs.g.h"

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
	struct SuggestionRequestedEventArgs : SuggestionRequestedEventArgsT<SuggestionRequestedEventArgs>, winrt::deferrable_event_args<SuggestionRequestedEventArgs>
    {
        SuggestionRequestedEventArgs() = default;

        wil::single_threaded_rw_property<winrt::hstring> Prefix;

        wil::single_threaded_rw_property<winrt::hstring> QueryText;

        bool Cancel() const
        {
            return false;
		}
    };
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
    struct SuggestionRequestedEventArgs : SuggestionRequestedEventArgsT<SuggestionRequestedEventArgs, implementation::SuggestionRequestedEventArgs>
    {
    };
}
