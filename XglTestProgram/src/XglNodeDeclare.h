#pragma once
#include "XglNode.h"
class XglNodeDeclare :
	public XglNode
{
public:
	XglNodeDeclare();
	virtual ~XglNodeDeclare();

public:
	XglValue *execute(XglContext *context);
};

