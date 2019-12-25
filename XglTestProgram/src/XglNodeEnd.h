#pragma once
#include "XglNode.h"
#include "XglValue.h"
#include "XglContext.h"

class XglNodeEnd :
	public XglNode
{
public:
	XglNodeEnd();
	virtual ~XglNodeEnd();

public:
	XglValue *execute(XglContext *context);
};

