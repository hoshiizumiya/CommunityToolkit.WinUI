# WinUI Community Toolkit (C++ Port)

This repository contains **C++ ports** of [CommunityToolkit](https://github.com/CommunityToolkit) components.

The goal is to allow seamless usage of these controls in WinUI 3 / C++ projects.

---

## NuGet Packages

You can install the C++ WinUI Community Toolkit packages via NuGet (it also supports .NET):

| Package | NuGet |
|---------|-------|
| XamlToolkit.WinUI.Native | [![NuGet](https://img.shields.io/nuget/v/XamlToolkit.WinUI.Native.svg)](https://www.nuget.org/packages/XamlToolkit.WinUI.Native/) |
| XamlToolkit.WinUI.Helpers.Native | [![NuGet](https://img.shields.io/nuget/v/XamlToolkit.WinUI.Helpers.Native.svg)](https://www.nuget.org/packages/XamlToolkit.WinUI.Helpers.Native/) |
| XamlToolkit.WinUI.Converters.Native | [![NuGet](https://img.shields.io/nuget/v/XamlToolkit.WinUI.Converters.Native.svg)](https://www.nuget.org/packages/XamlToolkit.WinUI.Converters.Native/) |
| XamlToolkit.WinUI.Media.Native | [![NuGet](https://img.shields.io/nuget/v/XamlToolkit.WinUI.Media.Native.svg)](https://www.nuget.org/packages/XamlToolkit.WinUI.Media.Native/) |
| XamlToolkit.Labs.WinUI.Native | [![NuGet](https://img.shields.io/nuget/v/XamlToolkit.Labs.WinUI.Native.svg)](https://www.nuget.org/packages/XamlToolkit.Labs.WinUI.Native/) |
| XamlToolkit.WinUI.Controls.Native | [![NuGet](https://img.shields.io/nuget/v/XamlToolkit.WinUI.Controls.Native.svg)](https://www.nuget.org/packages/XamlToolkit.WinUI.Controls.Native/) |

**Note:** When using the C# version, make sure to set the `<TargetFramework>` to:

```xml
<TargetFramework>net8.0-windows10.0.26100.0</TargetFramework>
```

## Controls

### MarkdownTextBlock

`MarkdownTextBlock` supports syntax highlighting for **C#, C++, XML, JSON, and Shell**.

![MarkdownTextBlock](docs/images/MarkdownTextBlock.webp)

### Marquee
![Marquee](docs/images/Marquee.webp)

### OpacityMaskView
![OpacityMaskView](docs/images/OpacityMaskView.png)

### Ribbon
![Ribbon](docs/images/Ribbon.png)

### Shimmer
![Shimmer](docs/images/Shimmer.webp)

### TokenView
![TokenView](docs/images/TokenView.png)

### ColorPicker / ColorPickerButton
![ColorPicker](docs/images/ColorPicker.png)

### DockPanel
![DockPanel](docs/images/DockPanel.png)

### ImageCropper
![ImageCropper](docs/images/ImageCropper.png)

### LayoutTransformControl
![LayoutTransformControl](docs/images/LayoutTransformControl.png)

### MetadataControl
![MetadataControl](docs/images/MetadataControl.png)

### HeaderedContentControl / HeaderedItemsControl / HeaderedTreeView
![HeaderedContentControl](docs/images/HeaderedContentControl.png)

### ConstrainedBox
![ConstrainedBox](docs/images/ConstrainedBox.png)

### RadialGauge
:warning: The `ValueStringFormat` property **does not support .NET string format syntax** and only supports **std::format syntax**.

![RadialGauge](docs/images/RadialGauge.png)

### RangeSelector
![RangeSelector](docs/images/RangeSelector.png)

### Segmented
![Segmented](docs/images/Segmented.png)

### SettingsCard / SettingsExpander
![SettingsCard](docs/images/SettingsCard.png)

### ContentSizer / GridSplitter / PropertySizer
![GridSplitter](docs/images/GridSplitter.png)

### StaggeredLayout
![StaggeredLayout](docs/images/StaggeredLayout.png)

### SwitchPresenter
![SwitchPresenter](docs/images/SwitchPresenter.png)

### TabbedCommandBar
![TabbedCommandBar](docs/images/TabbedCommandBar.png)

### TokenizingTextBox
![TokenizingTextBox](docs/images/TokenizingTextBox.png)

### UniformGrid
![UniformGrid](docs/images/UniformGrid.png)

### WrapPanel
![WrapPanel](docs/images/WrapPanel.png)

### AttachedDropShadow / AttachedCardShadow
![AttachedCardShadow](docs/images/AttachedCardShadow.png)

---

## Features

- Native C++/WinRT implementation for WinUI 3.
- API style compatible with CommunityToolkit controls.

## Build Steps

- Requires **Visual Studio 2022** or later for compilation.  
- To build `XamlToolkit.Labs.WinUI`, you need to install **tree-sitter** via vcpkg:

```powershell
vcpkg install tree-sitter:x64-windows-static
```
Markdown parsing uses **md4c** (<https://github.com/mity/md4c>).  
Since vcpkg does not support configuring UTF-16 character set for md4c, the project directly includes the md4c source code.

## Usage

### NuGet

Add nuget packages to your project.	

Add an XML namespace like this in your XAML

```bash
xmlns:ui="using:XamlToolkit.WinUI"
xmlns:controls="using:XamlToolkit.WinUI.Controls"
xmlns:convertors="using:XamlToolkit.WinUI.Convertors"
xmlns:labs="using:XamlToolkit.Labs.WinUI"
xmlns:media="using:XamlToolkit.WinUI.Media"
```

![Sample](docs/images/Sample.png)

