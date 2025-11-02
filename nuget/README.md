# WinUI Community Toolkit (C++ Port)

**XamlToolkit.WinUI.Native** provides **C++/WinRT ports** of [CommunityToolkit.WinUI](https://github.com/CommunityToolkit) controls,  
enabling seamless use of these components in **WinUI 3 / C++ projects**.

---

## ✨ Features

- 100% **native C++/WinRT** implementation.  
- API design consistent with **CommunityToolkit.WinUI**.  
- Suitable for WinUI 3 applications written in **C++**.  
- Includes modern controls and layout containers with full XAML integration.

---

## 🧩 Included Controls

- **MarkdownTextBlock** — syntax highlighting for *C#, C++, XML, JSON, Shell*.  
- **Marquee**, **OpacityMaskView**, **Shimmer**, **TokenView**  
- **ColorPicker**, **ColorPickerButton**, **DockPanel**, **ImageCropper**  
- **LayoutTransformControl**, **MetadataControl**  
- **HeaderedContentControl**, **HeaderedItemsControl**, **HeaderedTreeView**  
- **ConstrainedBox**, **RadialGauge**, **RangeSelector**, **Segmented**  
- **SettingsCard**, **SettingsExpander**, **ContentSizer**, **GridSplitter**, **PropertySizer**  
- **StaggeredLayout**, **SwitchPresenter**, **TabbedCommandBar**  
- **TokenizingTextBox**, **UniformGrid**, **WrapPanel**  
- **AttachedDropShadow**, **AttachedCardShadow**

> ⚠️ Note:  
> `RadialGauge.ValueStringFormat` uses **C++ `std::format` syntax** instead of .NET string format syntax.

---

## 🛠️ Installation

Add the package via **NuGet**:

```powershell
dotnet add package XamlToolkit.WinUI.Controls.Native