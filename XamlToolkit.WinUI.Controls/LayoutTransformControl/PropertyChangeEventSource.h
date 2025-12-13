#pragma once
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Windows.Foundation.h>

namespace winrt::XamlToolkit::WinUI::Controls
{
	template <typename TPropertyType>
	struct PropertyChangeEventSource
	{
	private:
		winrt::Microsoft::UI::Xaml::DependencyObject _source;
		winrt::Microsoft::UI::Xaml::DependencyProperty _property;
		std::optional<int64_t> _registrationToken;

		winrt::event<winrt::Windows::Foundation::EventHandler<TPropertyType>> _valueChanged;

	public:
		PropertyChangeEventSource(const PropertyChangeEventSource&) = delete;
		PropertyChangeEventSource& operator=(const PropertyChangeEventSource&) = delete;
		PropertyChangeEventSource(PropertyChangeEventSource&&) = delete;
		PropertyChangeEventSource& operator=(PropertyChangeEventSource&&) = delete;

		PropertyChangeEventSource(
			winrt::Microsoft::UI::Xaml::DependencyObject const& source,
			winrt::Microsoft::UI::Xaml::DependencyProperty const& property)
			: _source(source), _property(property)
		{
			_registrationToken = source.RegisterPropertyChangedCallback(property,
				[this](winrt::Microsoft::UI::Xaml::DependencyObject const& sender,
					winrt::Microsoft::UI::Xaml::DependencyProperty const& dp)
				{
					auto value = winrt::unbox_value<TPropertyType>(sender.GetValue(dp));
					_valueChanged(nullptr, value);
				});
		}

		winrt::event_token ValueChanged(winrt::Windows::Foundation::EventHandler<TPropertyType> const& handler)
		{
			return _valueChanged.add(handler);
		}

		void ValueChanged(winrt::event_token token)
		{
			_valueChanged.remove(token);
		}

		TPropertyType Value() { return winrt::unbox_value<TPropertyType>(_source.GetValue(_property)); }

		void Value(TPropertyType const& value) { _source.SetValue(winrt::box_value(_property)); }

		void Unregister()
		{
			if (_registrationToken)
			{
				_source.UnregisterPropertyChangedCallback(_property, *_registrationToken);
				_registrationToken.reset();
			}
		}

		~PropertyChangeEventSource()
		{
			Unregister();
		}
	};
}