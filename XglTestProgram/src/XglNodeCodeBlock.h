#pragma once
#include "XglNode.h"
class XglNodeCodeBlock :
	public XglNode
{
public:
	XglNodeCodeBlock();
	virtual ~XglNodeCodeBlock();

public:
	virtual XglValue *execute();
};

