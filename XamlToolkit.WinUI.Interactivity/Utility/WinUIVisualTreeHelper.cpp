#include "pch.h"
#include "WinUIVisualTreeHelper.h"
#include <winrt/Microsoft.UI.Xaml.Media.h>

namespace winrt::XamlToolkit::WinUI::Interactivity
{
    winrt::DependencyObject WinUIVisualTreeHelper::GetParent(winrt::DependencyObject const& reference) const
    {
        return winrt::Microsoft::UI::Xaml::Media::VisualTreeHelper::GetParent(reference);
    }
}
