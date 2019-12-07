#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeGt :
	public XglNode
{
public:
	XglNodeGt();
	virtual ~XglNodeGt();

public:
	XglValue *execute(XglContext &context);
};

