#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeLt :
	public XglNode
{
public:
	XglNodeLt();
	virtual ~XglNodeLt();

public:
	XglValue *execute(XglContext *context);
};

