#pragma once

#include <winrt/Microsoft.UI.Xaml.Media.Animation.h>
#include <winrt/Windows.Foundation.h>
#include <functional>
#include <synchapi.h>

namespace winrt::XamlToolkit::WinUI::Animations
{
    using namespace winrt::Microsoft::UI::Xaml::Media::Animation;

    /// <summary>
    /// An extension class for the <see cref="Storyboard"/> type.
    /// </summary>
    class StoryboardAnimations
    {
    public:
        /// <summary>
        /// Starts an animation and returns an async action that reports when it completes.
        /// </summary>
        /// <param name="storyboard">The target storyboard to start.</param>
        /// <returns>An <see cref="IAsyncAction"/> that completes when <paramref name="storyboard"/> completes.</returns>
        static winrt::Windows::Foundation::IAsyncAction BeginAsync(Storyboard const& storyboard)
        {
            winrt::event_token token;
            auto tcs = std::make_shared<winrt::handle>(CreateEventW(nullptr, true, false, nullptr));
            token = storyboard.Completed([=](auto&&...)
            {
                SetEvent(tcs->get());
            });

            winrt::apartment_context context;
            storyboard.Begin();
            co_await winrt::resume_on_signal(tcs->get());
            co_await context;
            storyboard.Completed(token);
        }
    };
}
