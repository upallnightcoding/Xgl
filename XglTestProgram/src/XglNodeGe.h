#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeGe :
	public XglNode
{
public:
	XglNodeGe();
	virtual ~XglNodeGe();

public:
	XglValue *execute(XglContext *context);
};

