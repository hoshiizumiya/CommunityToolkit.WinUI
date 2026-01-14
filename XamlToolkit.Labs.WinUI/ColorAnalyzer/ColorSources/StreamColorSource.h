#pragma once

#include "StreamColorSource.g.h"
#include "ColorSource.h"

namespace winrt::XamlToolkit::Labs::WinUI::implementation
{
    struct StreamColorSource : StreamColorSourceT<StreamColorSource, implementation::ColorSource>
    {
        StreamColorSource() = default;

        static const wil::single_threaded_property<winrt::Microsoft::UI::Xaml::DependencyProperty> SourceProperty;

        winrt::Windows::Storage::Streams::IRandomAccessStream Source() const;
        void Source(winrt::Windows::Storage::Streams::IRandomAccessStream const& value);

        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Streams::IRandomAccessStream> GetPixelDataAsync(int requestedSamples) override;

    private:
        static void OnSourceChanged(
            winrt::Microsoft::UI::Xaml::DependencyObject const& d,
            winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);
    };
}

namespace winrt::XamlToolkit::Labs::WinUI::factory_implementation
{
    struct StreamColorSource : StreamColorSourceT<StreamColorSource, implementation::StreamColorSource>
    {
    };
}
