#pragma once

#include "Activity.g.h"

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    struct Activity : ActivityT<Activity>
    {
    public:
        Activity() = default;

        virtual winrt::Windows::Foundation::IAsyncAction InvokeAsync(Microsoft::UI::Xaml::UIElement const& element)
        {
            co_return;
        }
    };
}

namespace winrt::XamlToolkit::WinUI::Animations::factory_implementation
{
    struct Activity : ActivityT<Activity, implementation::Activity> {};
}
