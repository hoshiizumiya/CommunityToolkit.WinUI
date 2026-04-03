#pragma once
namespace winrt::XamlToolkit::WinUI::Animations
{
    /// <summary>
    /// Indicates a side to animate in the bounds of a given element.
    /// </summary>
    enum class Side
    {
        /// <summary>
        /// Maps the top side of the target bounds.
        /// </summary>
        Top,

        /// <summary>
        /// Maps the bottom side of the target bounds.
        /// </summary>
        Bottom,

        /// <summary>
        /// Maps the left side of the target bounds.
        /// </summary>
        Left,

        /// <summary>
        /// Maps the right side of the target bounds.
        /// </summary>
        Right
    };
}
