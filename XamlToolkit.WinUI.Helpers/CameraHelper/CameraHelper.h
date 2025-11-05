#pragma once

#include "CameraHelper.g.h"
#include <winrt/Windows.Media.Capture.Frames.h>
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>
#include <semaphore>

namespace winrt::XamlToolkit::WinUI::Helpers::implementation
{
	using namespace winrt::Windows::Foundation;
	using namespace winrt::Windows::Foundation::Collections;
    using namespace winrt::Windows::Media::Capture;
    using namespace winrt::Windows::Media::Capture::Frames;

    struct CameraHelper : CameraHelperT<CameraHelper>
    {
        CameraHelper() = default;

        MediaFrameSourceGroup FrameSourceGroup();

        void FrameSourceGroup(MediaFrameSourceGroup const& value);

        IVectorView<MediaFrameFormat> FrameFormatsAvailable();

        MediaFrameSource PreviewFrameSource();

        wil::untyped_event<winrt::XamlToolkit::WinUI::Helpers::FrameEventArgs> FrameArrived;

        IAsyncOperation<winrt::XamlToolkit::WinUI::Helpers::CameraHelperResult> InitializeAndStartCaptureAsync();

        static IAsyncOperation<IVectorView<MediaFrameSourceGroup>> GetFrameSourceGroupsAsync();

        IAsyncAction CleanUpAsync();

        void Close();

    private:
        std::binary_semaphore _semaphoreSlim{ 1 };

        static inline IVectorView<MediaFrameSourceGroup> _frameSourceGroups{ nullptr };

        MediaCapture _mediaCapture{ nullptr };
        MediaFrameReader _frameReader{ nullptr };
        MediaFrameSourceGroup _group{ nullptr };
        MediaFrameSource _previewFrameSource{ nullptr };
        IVectorView<MediaFrameFormat> _frameFormatsAvailable{ nullptr };

        bool _groupChanged = false;
        bool _initialized = false;
        bool _disposed = false;

		MediaFrameReader::FrameArrived_revoker _frameArrivedRevoker;

        IAsyncOperation<winrt::XamlToolkit::WinUI::Helpers::CameraHelperResult> InitializeMediaCaptureAsync();

        winrt::Windows::Foundation::IAsyncAction StopReaderAsync();

        void Reader_FrameArrived(MediaFrameReader const& sender, MediaFrameArrivedEventArgs const& args);
    };
}

namespace winrt::XamlToolkit::WinUI::Helpers::factory_implementation
{
    struct CameraHelper : CameraHelperT<CameraHelper, implementation::CameraHelper>
    {
    };
}
