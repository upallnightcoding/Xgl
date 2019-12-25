#pragma once
#include "XglNode.h"
class XglNodeTriplet :
	public XglNode
{
public:
	XglNodeTriplet(XglNode *expression, XglNode *truePart, XglNode *falsePart);
	virtual ~XglNodeTriplet();

public:
	XglValue *XglNodeTriplet::execute(XglContext *context);

private:
	XglNode *expression;
	XglNode *truePart;
	XglNode *falsePart;
};

