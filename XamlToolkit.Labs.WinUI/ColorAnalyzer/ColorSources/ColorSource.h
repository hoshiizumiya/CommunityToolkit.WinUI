#pragma once

#include "ColorSource.g.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>

namespace winrt::XamlToolkit::Labs::WinUI::implementation
{
    struct ColorSource : ColorSourceT<ColorSource>
    {
        ColorSource() = default;

        wil::untyped_event<IInspectable> SourceUpdated;

        virtual winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Streams::IRandomAccessStream> GetPixelDataAsync([[maybe_unused]] int32_t requestedSamples) { return nullptr;  };

        void InvokeSourceUpdated() { SourceUpdated.invoke(*this, nullptr); }
    };
}

namespace winrt::XamlToolkit::Labs::WinUI::factory_implementation
{
    struct ColorSource : ColorSourceT<ColorSource, implementation::ColorSource>
    {
    };
}
