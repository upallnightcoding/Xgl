#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeLe :
	public XglNode
{
public:
	XglNodeLe();
	virtual ~XglNodeLe();

public:
	XglValue *execute(XglContext &context);
};

