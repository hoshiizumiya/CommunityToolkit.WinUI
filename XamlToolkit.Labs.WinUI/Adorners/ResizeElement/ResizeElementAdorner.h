#pragma once

#include "ResizeElementAdorner.g.h"

namespace winrt::XamlToolkit::Labs::WinUI::implementation
{
	struct ResizeElementAdorner : ResizeElementAdornerT<ResizeElementAdorner, implementation::Adorner>
	{
		ResizeElementAdorner();

		FrameworkElement AdornedElement() const
		{
			return base_type::AdornedElement().try_as<FrameworkElement>();
		}

		void OnApplyTemplate();

		void OnAttached() override;

		void OnDetaching() override;

	private:
		void OnTargetManipulated(IInspectable const& sender, ManipulationDeltaRoutedEventArgs const& e);

		void OnTargetControlResized(winrt::XamlToolkit::Labs::WinUI::ResizeThumb const& sender, ITargetControlResizedEventArgs const& args);

		winrt::XamlToolkit::Labs::WinUI::ResizeThumb TopThumbPart{ nullptr };
		winrt::XamlToolkit::Labs::WinUI::ResizeThumb BottomThumbPart{ nullptr };
		winrt::XamlToolkit::Labs::WinUI::ResizeThumb LeftThumbPart{ nullptr };
		winrt::XamlToolkit::Labs::WinUI::ResizeThumb RightThumbPart{ nullptr };
		winrt::XamlToolkit::Labs::WinUI::ResizeThumb TopLeftThumbPart{ nullptr };
		winrt::XamlToolkit::Labs::WinUI::ResizeThumb TopRightThumbPart{ nullptr };
		winrt::XamlToolkit::Labs::WinUI::ResizeThumb BottomLeftThumbPart{ nullptr };
		winrt::XamlToolkit::Labs::WinUI::ResizeThumb BottomRightThumbPart{ nullptr };

		UIElement::ManipulationDelta_revoker _manipulationDeltaRevoker;
		std::array<winrt::event_token, 8> _thumbTokens;
	};
}

namespace winrt::XamlToolkit::Labs::WinUI::factory_implementation
{
	struct ResizeElementAdorner : ResizeElementAdornerT<ResizeElementAdorner, implementation::ResizeElementAdorner>
	{
	};
}
