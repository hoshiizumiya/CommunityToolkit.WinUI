#include "pch.h"
#include "RibbonGroup.h"
#if __has_include("RibbonGroup.g.cpp")
#include "RibbonGroup.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::XamlToolkit::Labs::WinUI::implementation
{
    RibbonGroup::RibbonGroup()
    {
        DefaultStyleKey(winrt::box_value(winrt::xaml_typename<class_type>()));
    }

    void RibbonGroup::OnApplyTemplate() { base_type::OnApplyTemplate(); }
}
