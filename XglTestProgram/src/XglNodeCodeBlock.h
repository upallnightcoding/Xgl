#pragma once
#include "XglNode.h"
#include "XglContext.h"

class XglNodeCodeBlock :
	public XglNode
{
public:
	XglNodeCodeBlock();
	virtual ~XglNodeCodeBlock();

public:
	virtual XglValue *execute(XglContext *context);
};

