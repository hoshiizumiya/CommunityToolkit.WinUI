#pragma once

#include "TokenItemAddingEventArgs.g.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
	struct TokenItemAddingEventArgs : TokenItemAddingEventArgsT<TokenItemAddingEventArgs>, winrt::deferrable_event_args<TokenItemAddingEventArgs>
    {
        TokenItemAddingEventArgs() = default;

        TokenItemAddingEventArgs(winrt::hstring const& token) : TokenText(token) {};

        wil::single_threaded_rw_property<winrt::hstring> TokenText;

        wil::single_threaded_rw_property<IInspectable> Item;

        wil::single_threaded_rw_property<bool> Cancel;
    };
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
    struct TokenItemAddingEventArgs : TokenItemAddingEventArgsT<TokenItemAddingEventArgs, implementation::TokenItemAddingEventArgs>
    {
    };
}
