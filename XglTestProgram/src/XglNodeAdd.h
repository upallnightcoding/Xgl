#pragma once
#include "XglNode.h"
class XglNodeAdd :
	public XglNode
{
public:
	XglNodeAdd();
	virtual ~XglNodeAdd();

public:
	virtual XglValue *execute(XglContext *context);
};

