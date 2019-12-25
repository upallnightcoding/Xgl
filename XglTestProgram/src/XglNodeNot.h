#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeNot :
	public XglNode
{
public:
	XglNodeNot();
	virtual ~XglNodeNot();

public:
	XglValue *execute(XglContext *context);
};

