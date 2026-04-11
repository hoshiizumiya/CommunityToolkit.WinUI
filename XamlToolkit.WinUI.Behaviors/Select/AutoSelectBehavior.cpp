#include "pch.h"
#include "AutoSelectBehavior.h"
#if __has_include("AutoSelectBehavior.g.cpp")
#include "AutoSelectBehavior.g.cpp"
#endif

namespace winrt::XamlToolkit::WinUI::Behaviors::implementation
{
    void AutoSelectBehavior::OnAssociatedObjectLoaded()
    {
        BehaviorBase::AssociatedObject().SelectAll();
    }
}