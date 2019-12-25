#pragma once
#include "XglNode.h"
#include "XglValue.h"
#include "XglContext.h"

class XglNodeMult :
	public XglNode
{
public:
	XglNodeMult();
	virtual ~XglNodeMult();

public:
	virtual XglValue *execute(XglContext *context);
};

