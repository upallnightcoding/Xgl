#pragma once
#include "XglNode.h"
class XglNodeConst :
	public XglNode
{
public:
	XglNodeConst();
	virtual ~XglNodeConst();

public:
	XglValue *execute(XglContext *context);
};

