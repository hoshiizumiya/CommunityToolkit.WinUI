#pragma once

#include <winrt/Microsoft.UI.Xaml.h>

namespace winrt::XamlToolkit::WinUI::Animations
{
    /// <summary>
    /// Internal class for connected animation list property.
    /// </summary>
    struct ConnectedAnimationListProperty
    {
        winrt::hstring ElementName;
        Microsoft::UI::Xaml::Controls::ListViewBase ListViewBase{ nullptr };
    };
}
