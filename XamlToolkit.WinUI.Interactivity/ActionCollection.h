#pragma once

#include "ActionCollection.g.h"

namespace winrt
{
    using namespace Microsoft::UI::Xaml;
    using namespace Windows::Foundation::Collections;
}

namespace winrt::XamlToolkit::WinUI::Interactivity::implementation
{
    /// <summary>
    /// Represents a collection of IActions.
    /// </summary>
    struct ActionCollection : ActionCollectionT<ActionCollection>
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="ActionCollection"/> class.
        /// </summary>
        ActionCollection();

    private:
        void OnVectorChanged(
            winrt::IObservableVector<winrt::DependencyObject> const& sender,
            winrt::IVectorChangedEventArgs const& eventArgs);

        static void VerifyType(winrt::DependencyObject const& item);
    };
}

namespace winrt::XamlToolkit::WinUI::Interactivity::factory_implementation
{
    struct ActionCollection : ActionCollectionT<ActionCollection, implementation::ActionCollection>
    {
    };
}
