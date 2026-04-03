#pragma once

#include "ExpressionNode.h"
#include "ExpressionNodeType.h"

namespace winrt::XamlToolkit::WinUI::Animations::Expressions
{
    class BooleanNode final : public ExpressionNodeBase<BooleanNode>
    {
    public:
        BooleanNode() = default;

        explicit BooleanNode(bool value)
            : value(value)
        {
            NodeType = ExpressionNodeType::ConstantValue;
        }

        explicit BooleanNode(winrt::hstring const& paramName)
        {
            ParamName = paramName;
            NodeType = ExpressionNodeType::ConstantParameter;
        }

        BooleanNode(winrt::hstring const& paramName, bool value)
            : value(value)
        {
            ParamName = paramName;
            NodeType = ExpressionNodeType::ConstantParameter;
            SetBooleanParameter(paramName, value);
        }

    protected:
        winrt::hstring GetValue() const override
        {
            return value ? L"true" : L"false";
        }

    private:
        bool value{};
    };
}
