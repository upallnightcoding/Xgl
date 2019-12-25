#pragma once
#include "XglNode.h"
class XglNodeNe :
	public XglNode
{
public:
	XglNodeNe();
	virtual ~XglNodeNe();

public:
	XglValue *execute(XglContext *context);
};

