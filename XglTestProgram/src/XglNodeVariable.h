#pragma once
#include "XglNode.h"
class XglNodeVariable :
	public XglNode
{
public:
	XglNodeVariable(XglValue *variable);
	virtual ~XglNodeVariable();

public:
	XglValue *execute(XglContext *context);

public:
	XglValue *variable;
};

