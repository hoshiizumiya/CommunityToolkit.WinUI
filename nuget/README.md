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

- **MarkdownTextBlock** — syntax highlighting for *C#, C++, XML, JSON, Shell*  
- **Marquee**, **OpacityMaskView**, **Shimmer**, **Adorner**  
- **AttachedDropShadow**, **AttachedCardShadow**  
- **ColorPicker**, **ColorPickerButton**, **ColorAnalyzer**  
- **DockPanel**, **UniformGrid**, **WrapPanel**, **StaggeredPanel**, **StaggeredLayout**, **GridSplitter**  
- **LayoutTransformControl**, **ContentSizer**, **PropertySizer**, **ConstrainedBox**  
- **HeaderedContentControl**, **HeaderedItemsControl**, **HeaderedTreeView**  
- **TokenView**, **TokenizingTextBox**, **RichSuggestBox**  
- **Segmented**, **SwitchPresenter**, **RangeSelector**, **RadialGauge**  
- **SettingsCard**, **SettingsExpander**, **TabbedCommandBar**  
- **ImageCropper**, **CameraPreview**  
- **RivePlayer**  
- **DataTable**, **MetadataControl**

> ⚠️ Note:  
> `RadialGauge.ValueStringFormat` uses **C++ `std::format` syntax** instead of .NET string format syntax.

---

## 🛠️ Installation

Add the package via **NuGet**:

```powershell
dotnet add package XamlToolkit.WinUI.Controls.Native