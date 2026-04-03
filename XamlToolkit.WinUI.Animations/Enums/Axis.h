#pragma once
namespace winrt::XamlToolkit::WinUI::Animations
{
    /// <summary>
    /// Indicates an axis in the 3D space.
    /// </summary>
    enum class Axis
    {
        /// <summary>
        /// The X axis (horizontal).
        /// </summary>
        X,

        /// <summary>
        /// The Y axis (vertical).
        /// </summary>
        Y,

        /// <summary>
        /// The Z axis (depth).
        /// </summary>
        /// <remarks>
        /// This axis might only be available in certain scenarios, such as when working with composition APIs.
        /// </remarks>
        Z
    };
}
