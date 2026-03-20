#pragma once

#include "FrameworkElementExtensions.g.h"
#include <wil/wistd_type_traits.h>
#include <wil/cppwinrt_authoring.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <unordered_map>

namespace winrt::XamlToolkit::WinUI::implementation
{
    using namespace Microsoft::UI::Xaml;
    using namespace Windows::UI::Xaml::Interop;

    struct FrameworkElementExtensions : FrameworkElementExtensionsT<FrameworkElementExtensions>
    {
    private:
        struct HandlerState
        {
			winrt::event_token _loadedToken;
            winrt::event_token _unloadedToken;
        };

        struct WeakFrameworkElementHash
        {
            size_t operator()(winrt::weak_ref<FrameworkElement> const& element) const noexcept
            {
                return std::hash<void*>{}(winrt::get_abi(element).get());
            }
        };

        static void RemoveHandlers() noexcept;

        static thread_local inline std::unordered_map<winrt::weak_ref<FrameworkElement>, HandlerState, WeakFrameworkElementHash> _handlerStates;

    public:
        static void AncestorType_PropertyChanged(DependencyObject const& obj, DependencyPropertyChangedEventArgs const& args);

        static DependencyObject FindAscendant(DependencyObject element, TypeName const& name);

        static void FrameworkElement_Loaded(IInspectable const& sender, RoutedEventArgs const& e);

        static void FrameworkElement_Unloaded(IInspectable const& sender, RoutedEventArgs const& e);

        static IInspectable GetAncestor(DependencyObject const& obj);

        static void SetAncestor(DependencyObject const& obj, IInspectable const& value);

        static TypeName GetAncestorType(FrameworkElement const& obj);

        static void SetAncestorType(FrameworkElement const& obj, TypeName const& value);

        static inline const wil::single_threaded_property<DependencyProperty> AncestorProperty =
            DependencyProperty::RegisterAttached(L"Ancestor", winrt::xaml_typename<IInspectable>(), winrt::xaml_typename<class_type>(), PropertyMetadata(nullptr));

        static inline const wil::single_threaded_property<DependencyProperty> AncestorTypeProperty =
            DependencyProperty::RegisterAttached(L"AncestorType", winrt::xaml_typename<TypeName>(), winrt::xaml_typename<class_type>(), PropertyMetadata(nullptr, AncestorType_PropertyChanged));
    };
}

namespace winrt::XamlToolkit::WinUI::factory_implementation
{
    struct FrameworkElementExtensions : FrameworkElementExtensionsT<FrameworkElementExtensions, implementation::FrameworkElementExtensions>
    {
    };
}