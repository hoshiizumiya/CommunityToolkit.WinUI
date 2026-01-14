#pragma once
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.h>

namespace winrt::XamlToolkit::Labs::WinUI::implementation
{
    struct ColorPaletteSelectorExtensions
    {
        static winrt::Windows::Foundation::Collections::IVector<winrt::Windows::UI::Color> EnsureMinColorCount(
            winrt::Windows::Foundation::Collections::IVector<winrt::Windows::UI::Color> colors, uint32_t minCount, uint32_t index = 0)
        {
            // If we already have enough colors, do nothing.
            if (colors.Size() >= minCount)
                return colors;

            auto nthColor = colors.GetAt(index);
            while (colors.Size() < minCount)
            {
                colors.Append(nthColor);
            }

            return colors;
        }
    };
}