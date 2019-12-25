#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeDivide :
	public XglNode
{
public:
	XglNodeDivide();
	virtual ~XglNodeDivide();

public:
	virtual XglValue *execute(XglContext *context);
};

