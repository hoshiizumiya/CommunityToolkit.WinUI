#pragma once

#include "SettingsExpanderAutomationPeer.g.h"

#include <winrt/Microsoft.UI.Xaml.Automation.h>
#include <winrt/Microsoft.UI.Xaml.Automation.Peers.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
    using namespace winrt;
    using namespace Microsoft::UI::Xaml::Automation;
    using namespace Microsoft::UI::Xaml::Automation::Peers;

    struct SettingsExpanderAutomationPeer : SettingsExpanderAutomationPeerT<SettingsExpanderAutomationPeer>
    {
        using owner_type = XamlToolkit::WinUI::Controls::SettingsExpander;

        SettingsExpanderAutomationPeer() = default;

        SettingsExpanderAutomationPeer(owner_type const& owner);

        AutomationControlType GetAutomationControlTypeCore();

        hstring GetClassNameCore();

        hstring GetNameCore();

        void RaiseExpandedChangedEvent(bool newValue);
    };
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
    struct SettingsExpanderAutomationPeer : SettingsExpanderAutomationPeerT<SettingsExpanderAutomationPeer, implementation::SettingsExpanderAutomationPeer>
    {
    };
}
