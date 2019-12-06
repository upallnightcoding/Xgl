#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeNeg :
	public XglNode
{
public:
	XglNodeNeg();
	virtual ~XglNodeNeg();

public:
	XglValue *execute(XglContext &context);
};

