#pragma once

#include <winrt/Microsoft.UI.Xaml.h>
#include "ConnectedAnimationListProperty.h"
#include <vector>

namespace winrt::XamlToolkit::WinUI::Animations
{
    /// <summary>
    /// Internal class for connected animation properties.
    /// </summary>
    struct ConnectedAnimationProperties
    {
        winrt::hstring Key;
        winrt::Microsoft::UI::Xaml::UIElement Element{ nullptr };
        std::vector<ConnectedAnimationListProperty> ListAnimProperties;

        bool IsListAnimation() const
        {
            return !ListAnimProperties.empty();
        }
    };
}
