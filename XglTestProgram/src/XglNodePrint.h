#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodePrint :
	public XglNode
{
public:
	XglNodePrint();
	virtual ~XglNodePrint();

public:
	virtual XglValue *execute(XglContext &context);
};

