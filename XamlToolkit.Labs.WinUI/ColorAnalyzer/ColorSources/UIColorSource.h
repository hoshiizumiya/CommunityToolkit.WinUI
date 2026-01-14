#pragma once

#include "UIColorSource.g.h"
#include "ColorSource.h"

namespace winrt::XamlToolkit::Labs::WinUI::implementation
{
    struct UIColorSource : UIColorSourceT<UIColorSource, implementation::ColorSource>
    {
        UIColorSource() = default;

        static const wil::single_threaded_property<winrt::Microsoft::UI::Xaml::DependencyProperty> SourceProperty;

        UIElement Source() const;
        void Source(UIElement const& value);

        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Streams::IRandomAccessStream> GetPixelDataAsync(int requestedSamples) override;

    private:
        static void OnSourceChanged(
            winrt::Microsoft::UI::Xaml::DependencyObject const& d,
            winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);
    };
}

namespace winrt::XamlToolkit::Labs::WinUI::factory_implementation
{
    struct UIColorSource : UIColorSourceT<UIColorSource, implementation::UIColorSource>
    {
    };
}
