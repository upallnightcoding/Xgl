#pragma once
#include "XglNode.h"
class XglNodeFunction :
	public XglNode
{
public:
	XglNodeFunction();
	virtual ~XglNodeFunction();

public:
	XglValue *execute(XglContext *context);
};

