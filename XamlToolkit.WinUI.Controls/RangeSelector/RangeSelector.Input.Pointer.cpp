#include "pch.h"
#include "RangeSelector.h"

namespace winrt::XamlToolkit::WinUI::Controls::implementation
{
    void RangeSelector::ContainerCanvas_PointerEntered([[maybe_unused]] IInspectable const& sender, [[maybe_unused]] PointerRoutedEventArgs const& e)
    {
        VisualStateManager::GoToState(*this, PointerOverState, false);
    }

    void RangeSelector::ContainerCanvas_PointerExited([[maybe_unused]] IInspectable const& sender, PointerRoutedEventArgs const& e)
    {
        double position = GetPointerAxisPosition(e);
        double percent = IsHorizontal() ? (position / DragLength()) : (1.0 - position / DragLength());
        double normalizedPosition = Minimum() + percent * (Maximum() - Minimum());

        if (_pointerManipulatingMin)
        {
            _pointerManipulatingMin = false;
            auto args = winrt::make_self<RangeChangedEventArgs>(RangeStart(), normalizedPosition, RangeSelectorProperty::MinimumValue);
            OnValueChanged(*args);
        }
        else if (_pointerManipulatingMax)
        {
            _pointerManipulatingMax = false;
            auto args = winrt::make_self<RangeChangedEventArgs>(RangeEnd(), normalizedPosition, RangeSelectorProperty::MaximumValue);
            OnValueChanged(*args);
        }

        if (_containerCanvas != nullptr)
        {
            _containerCanvas.IsHitTestVisible(true);
        }

        if (_toolTip != nullptr)
        {
            _toolTip.IsOpen(false);
        }

        VisualStateManager::GoToState(*this, NormalState, false);
    }

    void RangeSelector::ContainerCanvas_PointerReleased([[maybe_unused]] IInspectable const& sender, PointerRoutedEventArgs const& e)
    {
        double position = GetPointerAxisPosition(e);
        double percent = IsHorizontal() ? (position / DragLength()) : (1.0 - position / DragLength());
        double normalizedPosition = Minimum() + percent * (Maximum() - Minimum());

        if (_pointerManipulatingMin)
        {
            _pointerManipulatingMin = false;
            auto args = winrt::make_self<RangeChangedEventArgs>(RangeStart(), normalizedPosition, RangeSelectorProperty::MinimumValue);
            OnValueChanged(*args);
        }
        else if (_pointerManipulatingMax)
        {
            _pointerManipulatingMax = false;
            auto args = winrt::make_self<RangeChangedEventArgs>(RangeEnd(), normalizedPosition, RangeSelectorProperty::MaximumValue);
            OnValueChanged(*args);
        }

        if (_containerCanvas != nullptr)
        {
            _containerCanvas.IsHitTestVisible(true);
        }

        SyncThumbs();

        if (_toolTip != nullptr)
        {
            _toolTip.IsOpen(false);
        }
    }

    void RangeSelector::ContainerCanvas_PointerMoved([[maybe_unused]] IInspectable const& sender, PointerRoutedEventArgs const& e)
    {
        double position = GetPointerAxisPosition(e);

        if (_pointerManipulatingMin)
        {
            RangeStart(DragThumb(_minThumb, 0, DragLength(), position));
            if (_toolTipText != nullptr)
            {
                UpdateToolTipText(*this, _toolTipText, RangeStart());
            }
        }
        else if (_pointerManipulatingMax)
        {
            if (_toolTipText != nullptr)
            {
                RangeEnd(DragThumb(_maxThumb, 0, DragLength(), position));
                UpdateToolTipText(*this, _toolTipText, RangeEnd());
            }
        }
    }

    void RangeSelector::ContainerCanvas_PointerPressed([[maybe_unused]] IInspectable const& sender, PointerRoutedEventArgs const& e)
    {
        double position = GetPointerAxisPosition(e);
        double percent = IsHorizontal() ? (position / DragLength()) : (1.0 - position / DragLength());
        double normalizedPosition = Minimum() + percent * (Maximum() - Minimum());

        double upperValueDiff = std::abs(RangeEnd() - normalizedPosition);
        double lowerValueDiff = std::abs(RangeStart() - normalizedPosition);

        if (upperValueDiff < lowerValueDiff /*|| std::abs(upperValueDiff - lowerValueDiff) < 1e-6*/)
        {
            RangeEnd(normalizedPosition);
            _pointerManipulatingMax = true;
            if (_maxThumb != nullptr)
            {
                Thumb_DragStarted(_maxThumb);
            }
        }
        else
        {
            RangeStart(normalizedPosition);
            _pointerManipulatingMin = true;
            if (_minThumb != nullptr)
            {
                Thumb_DragStarted(_minThumb);
            }
        }

        SyncThumbs();
    }
}