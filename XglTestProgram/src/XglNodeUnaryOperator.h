#pragma once
#include "XglNode.h"
#include "XglValue.h"

class XglNodeUnaryOperator :
	public XglNode
{
public:
	XglNodeUnaryOperator(XglNodeType type);
	virtual ~XglNodeUnaryOperator();

	XglValue *execute(XglContext *context);

private:
	XglValue *neg(XglContext *context, XglValue *argument);
	XglValue *nott(XglContext *context, XglValue *argument);

private:
	XglNodeType type;

	XglValue *argument;
};

