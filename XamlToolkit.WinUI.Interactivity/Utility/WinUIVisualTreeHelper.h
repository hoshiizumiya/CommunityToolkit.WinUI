#pragma once

#include "IVisualTreeHelper.h"
#include <winrt/Microsoft.UI.Xaml.Media.h>

namespace winrt::XamlToolkit::WinUI::Interactivity
{
    struct WinUIVisualTreeHelper : IVisualTreeHelper
    {
        winrt::DependencyObject GetParent(winrt::DependencyObject const& reference) const override;
    };
}
