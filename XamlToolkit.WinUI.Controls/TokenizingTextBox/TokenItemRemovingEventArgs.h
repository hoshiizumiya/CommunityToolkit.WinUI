#pragma once

#include "TokenItemRemovingEventArgs.g.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
	struct TokenItemRemovingEventArgs : TokenItemRemovingEventArgsT<TokenItemRemovingEventArgs>, winrt::deferrable_event_args<TokenItemRemovingEventArgs>
    {
        TokenItemRemovingEventArgs() = default;

        TokenItemRemovingEventArgs(IInspectable const& item, winrt::XamlToolkit::WinUI::Controls::TokenizingTextBoxItem const& token): Item(item), Token(token) {}

        wil::single_threaded_property<IInspectable> Item;

        wil::single_threaded_property<winrt::XamlToolkit::WinUI::Controls::TokenizingTextBoxItem> Token;

        wil::single_threaded_rw_property<bool> Cancel;
    };
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
    struct TokenItemRemovingEventArgs : TokenItemRemovingEventArgsT<TokenItemRemovingEventArgs, implementation::TokenItemRemovingEventArgs>
    {
    };
}
