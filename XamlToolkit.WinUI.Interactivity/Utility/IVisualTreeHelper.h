#pragma once

#include <winrt/Microsoft.UI.Xaml.h>

namespace winrt 
{
	using namespace winrt::Microsoft::UI::Xaml;
}

namespace winrt::XamlToolkit::WinUI::Interactivity
{
    struct IVisualTreeHelper
    {
        virtual ~IVisualTreeHelper() = default;
        virtual winrt::DependencyObject GetParent(winrt::DependencyObject const& reference) const = 0;
    };
}
