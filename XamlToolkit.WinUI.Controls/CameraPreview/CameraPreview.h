#pragma once

#include "CameraPreview.g.h"
#include <winrt/Windows.Media.Capture.Frames.h>
#include <winrt/Windows.Media.Playback.h>

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
	using namespace winrt::Windows::Media::Capture::Frames;
	using namespace winrt::Windows::Media::Playback;
	using namespace winrt::XamlToolkit::WinUI::Helpers;

	struct CameraPreview : CameraPreviewT<CameraPreview>
	{
	private:
		static constexpr std::wstring_view Preview_MediaPlayerElementControl = L"MediaPlayerElementControl";
		static constexpr std::wstring_view Preview_FrameSourceGroupButton = L"FrameSourceGroupButton";

		CameraHelper _cameraHelper{ nullptr };
		MediaPlayer _mediaPlayer{ nullptr };
		MediaPlayerElement _mediaPlayerElementControl{ nullptr };
		Button _frameSourceGroupButton{ nullptr };

		IVectorView<MediaFrameSourceGroup> _frameSourceGroups{ nullptr };

		ButtonBase::Click_revoker _frameSourceGroupButtonClickRevoker;

		bool IsFrameSourceGroupButtonAvailable() { return _frameSourceGroups && _frameSourceGroups.Size() > 1; }

		static void IsFrameSourceGroupButtonVisibleChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const& e);

	public:
		static inline const wil::single_threaded_property<DependencyProperty> IsFrameSourceGroupButtonVisibleProperty =
			DependencyProperty::Register(
				L"IsFrameSourceGroupButtonVisible",
				winrt::xaml_typename<bool>(),
				winrt::xaml_typename<class_type>(),
				PropertyMetadata{ winrt::box_value(true), &CameraPreview::IsFrameSourceGroupButtonVisibleChanged });

		bool IsFrameSourceGroupButtonVisible() const
		{
			return winrt::unbox_value<bool>(GetValue(IsFrameSourceGroupButtonVisibleProperty));
		}

		void IsFrameSourceGroupButtonVisible(bool value)
		{
			SetValue(IsFrameSourceGroupButtonVisibleProperty, winrt::box_value(value));
		}

		wil::single_threaded_rw_property<winrt::XamlToolkit::WinUI::Helpers::CameraHelper> CameraHelper{ nullptr };

		wil::untyped_event<PreviewFailedEventArgs> PreviewFailed;

		IAsyncAction StartAsync();

		IAsyncAction StartAsync(winrt::XamlToolkit::WinUI::Helpers::CameraHelper cameraHelper);

		void Stop();

		CameraPreview();

		winrt::fire_and_forget OnApplyTemplate();

	private:
		IAsyncAction InitializeAsync();

		IAsyncAction FrameSourceGroupButton_ClickAsync(IInspectable const& sender, RoutedEventArgs const& e);

		void InvokePreviewFailed(winrt::hstring const& error);

		void SetMediaPlayerSource();

		void SetUIControls(CameraHelperResult result);

		void SetFrameSourceGroupButtonVisibility();
	};
}

namespace winrt::XamlToolkit::WinUI::Controls::factory_implementation
{
	struct CameraPreview : CameraPreviewT<CameraPreview, implementation::CameraPreview>
	{
	};
}
