#pragma once
#include "XglNode.h"
class XglNodeConstVar :
	public XglNode
{
public:
	XglNodeConstVar(XglToken *type, XglToken *variable, XglNode *expression);
	virtual ~XglNodeConstVar();

public:
	XglValue *execute(XglContext &context);

private:
	XglToken *type;
	XglToken *variable;
	XglNode *expression;
};

