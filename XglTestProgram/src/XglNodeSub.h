#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeSub :
	public XglNode
{
public:
	XglNodeSub();
	virtual ~XglNodeSub();

public:
	XglValue *execute(XglContext &context);
};

