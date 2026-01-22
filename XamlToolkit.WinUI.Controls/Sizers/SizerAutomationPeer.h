#pragma once

#include "SizerAutomationPeer.g.h"
#include <winrt/Microsoft.UI.Xaml.Automation.h>
#include <winrt/Microsoft.UI.Xaml.Automation.Peers.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
    using namespace winrt;
    using namespace winrt::Microsoft::UI::Xaml::Automation;
    using namespace winrt::Microsoft::UI::Xaml::Automation::Peers;

    struct SizerAutomationPeer : SizerAutomationPeerT<SizerAutomationPeer>
    {
        SizerAutomationPeer(XamlToolkit::WinUI::Controls::SizerBase owner)
            : SizerAutomationPeerT<SizerAutomationPeer>(owner)
        {
        }

        XamlToolkit::WinUI::Controls::SizerBase OwningSizer();

        winrt::hstring GetClassNameCore();

        winrt::hstring GetNameCore();
    };
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
    struct SizerAutomationPeer : SizerAutomationPeerT<SizerAutomationPeer, implementation::SizerAutomationPeer>
    {
    };
}
