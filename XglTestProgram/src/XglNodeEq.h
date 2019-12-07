#pragma once
#include "XglNode.h"
class XglNodeEq :
	public XglNode
{
public:
	XglNodeEq();
	virtual ~XglNodeEq();

public:
	XglValue *execute(XglContext &context);
};

