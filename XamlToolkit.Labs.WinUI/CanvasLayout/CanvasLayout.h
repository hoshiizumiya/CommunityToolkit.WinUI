#pragma once

#include "CanvasLayout.g.h"

namespace winrt::XamlToolkit::Labs::WinUI::implementation
{
	struct CanvasLayoutState : winrt::implements<CanvasLayoutState, ICanvasLayoutState>
	{
	public:
		CanvasLayoutState() : FirstRealizedIndex{ -1 }, LayoutRects{ winrt::single_threaded_vector<Rect>() } { }

		wil::single_threaded_rw_property<int> FirstRealizedIndex;
		wil::single_threaded_rw_property<IVector<Rect>> LayoutRects;
	};

	struct CanvasLayout : CanvasLayoutT<CanvasLayout>
	{
		CanvasLayout() = default;

#pragma region Setup / teardown
		void InitializeForContextCore(VirtualizingLayoutContext const& context);

		void UninitializeForContextCore(VirtualizingLayoutContext const& context);
#pragma endregion

#pragma region Layout
		Size MeasureOverride(VirtualizingLayoutContext const& context, Size availableSize);

		Size ArrangeOverride(VirtualizingLayoutContext const& context, Size finalSize);
#pragma endregion
	};
}

namespace winrt::XamlToolkit::Labs::WinUI::factory_implementation
{
	struct CanvasLayout : CanvasLayoutT<CanvasLayout, implementation::CanvasLayout>
	{
	};
}
