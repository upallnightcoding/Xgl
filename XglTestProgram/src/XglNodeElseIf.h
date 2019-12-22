#pragma once
#include "XglNode.h"
class XglNodeElseIf :
	public XglNode
{
public:
	XglNodeElseIf();
	virtual ~XglNodeElseIf();

public:
	XglValue *execute(XglContext &context);
};

