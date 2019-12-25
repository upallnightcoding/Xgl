#pragma once
#include "XglNode.h"
class XglNodeElse :
	public XglNode
{
public:
	XglNodeElse();
	virtual ~XglNodeElse();

public:
	XglValue *execute(XglContext *context);
};

