#pragma once
#include "XglNode.h"
class XglNodeBinaryOperator :
	public XglNode
{
public:
	XglNodeBinaryOperator(XglNodeType type);
	virtual ~XglNodeBinaryOperator();

	XglValue *execute(XglContext *context);

private:
	XglValue *add(XglContext *context, XglValue *value1, XglValue *value2);
	XglValue *sub(XglContext *context, XglValue *value1, XglValue *value2);
	XglValue *multi(XglContext *context, XglValue *value1, XglValue *value2);
	XglValue *divide(XglContext *context, XglValue *value1, XglValue *value2);

	XglValue *ge(XglContext *context, XglValue *value1, XglValue *value2);
	XglValue *ne(XglContext *context, XglValue *value1, XglValue *value2);
	XglValue *eq(XglContext *context, XglValue *value1, XglValue *value2);
	XglValue *gt(XglContext *context, XglValue *value1, XglValue *value2);
	XglValue *lt(XglContext *context, XglValue *value1, XglValue *value2);
	XglValue *le(XglContext *context, XglValue *value1, XglValue *value2);

private:
	XglNodeType type;

	XglValue *value1;
	XglValue *value2;
};

