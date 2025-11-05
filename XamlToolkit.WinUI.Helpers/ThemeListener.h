#pragma once

#include "ThemeListener.g.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>
#include <winrt/Windows.UI.ViewManagement.h>

namespace winrt::XamlToolkit::WinUI::Helpers::implementation
{
	using namespace winrt;
	using namespace Windows::UI::ViewManagement;
	using namespace Microsoft::UI::Xaml;
	using namespace Windows::Foundation;
	using namespace Microsoft::UI::Dispatching;

	struct ThemeListener : ThemeListenerT<ThemeListener>
	{
		wil::single_threaded_rw_property<ApplicationTheme> CurrentTheme;

		wil::single_threaded_rw_property<bool> IsHighContrast{ false };

		wil::single_threaded_rw_property<struct DispatcherQueue> DispatcherQueue{ nullptr };

		winrt::event<ThemeChangedHandler> _themeChanged;

		winrt::event_token ThemeChanged(ThemeChangedHandler const& handler);

		void ThemeChanged(winrt::event_token const& token) noexcept;

		ThemeListener() : ThemeListener(nullptr) {};

		ThemeListener(struct DispatcherQueue const& dispatcherQueue);

		void OnThemePropertyChangedAsync();

		winrt::hstring CurrentThemeName();

	private:
		AccessibilitySettings _accessible;
		UISettings _settings;

		void Accessible_HighContrastChanged(AccessibilitySettings const& sender, IInspectable const& args);

		// Note: This can get called multiple times during HighContrast switch, do we care?
		void Settings_ColorValuesChanged(UISettings const& sender, IInspectable const& args);

		void UpdateProperties();
	};
}

namespace winrt::XamlToolkit::WinUI::Helpers::factory_implementation
{
	struct ThemeListener : ThemeListenerT<ThemeListener, implementation::ThemeListener>
	{
	};
}
