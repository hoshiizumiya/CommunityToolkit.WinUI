#include "pch.h"
#include "Vector3KeyFrame.h"
#if __has_include("Vector3KeyFrame.g.cpp")
#include "Vector3KeyFrame.g.cpp"
#endif

namespace winrt::XamlToolkit::WinUI::Animations::implementation
{
    using namespace winrt::Microsoft::UI::Xaml;

    const wil::single_threaded_property<DependencyProperty> Vector3KeyFrame::ValueProperty =
        DependencyProperty::Register(
            L"Value",
            winrt::xaml_typename<winrt::hstring>(),
            winrt::xaml_typename<class_type>(),
            nullptr);
}
