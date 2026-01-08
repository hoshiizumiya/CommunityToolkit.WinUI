// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.
#pragma once

#include "../DefaultSVGRenderer.h"
#include "../Extension.h"
#include "IAddChild.h"
#include <winrt/XamlToolkit.Labs.WinUI.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Web.Http.h>
#include <winrt/Windows.Web.Http.Headers.h>

#undef LoadImage

namespace winrt::XamlToolkit::Labs::WinUI::TextElements
{
	using namespace Microsoft::UI::Xaml::Media::Imaging;
	using namespace winrt::Windows::Storage::Streams;
	using namespace winrt::Windows::Web::Http;

	class MdImage final : public IAddChild
	{
	private:
		InlineUIContainer _container;
		Microsoft::UI::Xaml::Controls::Image _image;
		Windows::Foundation::Uri _uri;
		IImageProvider _imageProvider{ nullptr };
		ISVGRenderer _svgRenderer{ nullptr };
		MarkdownThemes _themes{ nullptr };
		double _precedentWidth;
		double _precedentHeight;
		bool _loaded = false;

	public:
		Microsoft::UI::Xaml::Documents::TextElement TextElement() const override
		{
			return _container;
		}

		MdImage(Windows::Foundation::Uri const& uri, MarkdownConfig const& config)
			: _uri(uri), _precedentWidth(0), _precedentHeight(0)
		{
			_imageProvider = config.ImageProvider();
			_svgRenderer = config.SVGRenderer() ? config.SVGRenderer() : winrt::make<DefaultSVGRenderer>();
			_themes = config.Themes();

			Init();
			auto linkInline = uri.AbsoluteUri();
			auto size = Extensions::GetMarkdownImageSize(linkInline);
			if (size.Width != 0)
			{
				_precedentWidth = size.Width;
			}
			if (size.Height != 0)
			{
				_precedentHeight = size.Height;
			}
		}

		//MdImage(MarkdownConfig config)
		//{
		//    Windows::Foundation::Uri::Create(htmlNode.GetAttributeValue("src", "#"), UriKind::RelativeOrAbsolute, out _uri);

		//    _htmlNode = htmlNode;
		//    _imageProvider = config.ImageProvider();
		//    _svgRenderer = config.SVGRenderer() == nullptr ? DefaultSVGRenderer() : config.SVGRenderer();
		//    Init();
		//   /* int.TryParse(
		//        htmlNode.GetAttributeValue("width", "0"),
		//        NumberStyles.Integer,
		//        CultureInfo.InvariantCulture,
		//        out auto width
		//    );
		//    int.TryParse(
		//        htmlNode.GetAttributeValue("height", "0"),
		//        NumberStyles.Integer,
		//        CultureInfo.InvariantCulture,
		//        out auto height
		//    );
		//    if (width > 0)
		//    {
		//        _precedentWidth = width;
		//    }
		//    if (height > 0)
		//    {
		//        _precedentHeight = height;
		//    }*/
		//}

		void Init()
		{
			_image.Loaded({ this, &MdImage::LoadImage });
			_container.Child(_image);
		}

		winrt::Windows::Foundation::IAsyncAction LoadImage(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& e)
		{
			if (_loaded) co_return;
			try
			{
				if (_imageProvider != nullptr && _imageProvider.ShouldUseThisProvider(_uri.AbsoluteUri()))
				{
					_image = co_await _imageProvider.GetImage(_uri.AbsoluteUri());
					_container.Child(_image);
				}
				else
				{
					Windows::Web::Http::HttpClient client;

					// Download data from URL
					HttpResponseMessage response = co_await client.GetAsync(_uri);

					// Get the Content-Type header
					winrt::hstring contentType = response.Content().Headers().ContentType().MediaType();

					if (contentType == L"image/svg+xml")
					{
						winrt::hstring svgString = co_await response.Content().ReadAsStringAsync();
						if (const auto& resImage = co_await _svgRenderer.SvgToImage(svgString))
						{
							_image = resImage;
							_container.Child(_image);
						}
					}
					else
					{
						IBuffer data = co_await response.Content().ReadAsBufferAsync();
						// Create a BitmapImage for other supported formats
						BitmapImage bitmap;
						InMemoryRandomAccessStream stream;

						// Write the data to the stream
						co_await stream.WriteAsync(data);
						stream.Seek(0);

						// Set the source of the BitmapImage
						co_await bitmap.SetSourceAsync(stream);

						_image.Source(bitmap);
						_image.Width(bitmap.PixelWidth() == 0 ? bitmap.DecodePixelWidth() : bitmap.PixelWidth());
						_image.Height(bitmap.PixelHeight() == 0 ? bitmap.DecodePixelHeight() : bitmap.PixelHeight());
					}

					_loaded = true;
				}

				if (_precedentWidth != 0)
				{
					_image.Width(_precedentWidth);
				}
				if (_precedentHeight != 0)
				{
					_image.Height(_precedentHeight);
				}

				// Determine the actual image dimensions
				double actualWidth = _precedentWidth != 0 ? _precedentWidth : _image.Width();
				double actualHeight = _precedentHeight != 0 ? _precedentHeight : _image.Height();

				// Apply max constraints and calculate the final size
				// When using Uniform stretch with max constraints, we need to calculate
				// the actual rendered size to avoid gaps
				double finalWidth = actualWidth;
				double finalHeight = actualHeight;

				bool hasMaxWidth = _themes.ImageMaxWidth() > 0;
				bool hasMaxHeight = _themes.ImageMaxHeight() > 0;

				if (hasMaxWidth || hasMaxHeight)
				{
					double scaleX = hasMaxWidth && actualWidth > _themes.ImageMaxWidth()
						? _themes.ImageMaxWidth() / actualWidth
						: 1.0;
					double scaleY = hasMaxHeight && actualHeight > _themes.ImageMaxHeight()
						? _themes.ImageMaxHeight() / actualHeight
						: 1.0;

					// For Uniform stretch, use the smaller scale to maintain aspect ratio
					if (_themes.ImageStretch() == Stretch::Uniform || _themes.ImageStretch() == Stretch::UniformToFill)
					{
						double uniformScale = std::min(scaleX, scaleY);
						finalWidth = actualWidth * uniformScale;
						finalHeight = actualHeight * uniformScale;
					}
					else
					{
						// For other stretch modes, apply constraints independently
						finalWidth = actualWidth * scaleX;
						finalHeight = actualHeight * scaleY;
					}
				}

				_image.Width(finalWidth);
				_image.Height(finalHeight);
				_image.Stretch(_themes.ImageStretch());
			}
			catch (const winrt::hresult_error&) {}
		}

		void SetToolTip(winrt::hstring const& tooltip)
		{
			Microsoft::UI::Xaml::Controls::ToolTipService::SetToolTip(_image, winrt::box_value(tooltip));
		}
	};
}

