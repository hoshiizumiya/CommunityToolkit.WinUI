#pragma once

#include "CameraHelper.g.h"
#include <winrt/Windows.Media.Capture.Frames.h>
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>
#include <semaphore>

namespace winrt::XamlToolkit::WinUI::Helpers::implementation
{
    using namespace winrt::Windows::Media::Capture::Frames;

    struct CameraHelper : CameraHelperT<CameraHelper>
    {
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<
            winrt::Windows::Media::Capture::Frames::MediaFrameSourceGroup>> GetFrameSourceGroupsAsync();

        CameraHelper() = default;

        void Close();

        winrt::Windows::Media::Capture::Frames::MediaFrameSourceGroup FrameSourceGroup();

        void FrameSourceGroup(winrt::Windows::Media::Capture::Frames::MediaFrameSourceGroup const& value);

        winrt::Windows::Foundation::Collections::IVectorView<
            winrt::Windows::Media::Capture::Frames::MediaFrameFormat> FrameFormatsAvailable();

        winrt::Windows::Media::Capture::Frames::MediaFrameSource PreviewFrameSource();

        wil::untyped_event<winrt::XamlToolkit::WinUI::Helpers::FrameEventArgs> FrameArrived;

        winrt::Windows::Foundation::IAsyncOperation<
            winrt::XamlToolkit::WinUI::Helpers::CameraHelperResult> InitializeAndStartCaptureAsync();

        winrt::Windows::Foundation::IAsyncAction CleanUpAsync();

    private:
        std::binary_semaphore _semaphoreSlim{ 1 };

        static inline winrt::Windows::Foundation::Collections::IVectorView<
            winrt::Windows::Media::Capture::Frames::MediaFrameSourceGroup> _frameSourceGroups{ nullptr };

        winrt::Windows::Media::Capture::MediaCapture _mediaCapture{ nullptr };
        winrt::Windows::Media::Capture::Frames::MediaFrameReader _frameReader{ nullptr };
        winrt::Windows::Media::Capture::Frames::MediaFrameSourceGroup _group{ nullptr };
        winrt::Windows::Media::Capture::Frames::MediaFrameSource _previewFrameSource{ nullptr };
        winrt::Windows::Foundation::Collections::IVectorView<
            winrt::Windows::Media::Capture::Frames::MediaFrameFormat> _frameFormatsAvailable{ nullptr };

        bool _groupChanged = false;
        bool _initialized = false;
        bool _disposed = false;

		MediaFrameReader::FrameArrived_revoker _frameArrivedRevoker;

        winrt::Windows::Foundation::IAsyncOperation<
            winrt::XamlToolkit::WinUI::Helpers::CameraHelperResult> InitializeMediaCaptureAsync();

        winrt::Windows::Foundation::IAsyncAction StopReaderAsync();

        void Reader_FrameArrived(
            winrt::Windows::Media::Capture::Frames::MediaFrameReader const& sender,
            winrt::Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs const& args);
    };
}

namespace winrt::XamlToolkit::WinUI::Helpers::factory_implementation
{
    struct CameraHelper : CameraHelperT<CameraHelper, implementation::CameraHelper>
    {
    };
}
