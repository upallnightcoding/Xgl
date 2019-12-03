#pragma once
#include "XglNode.h"
#include "XglValue.h"

class XglNodeEnd :
	public XglNode
{
public:
	XglNodeEnd();
	virtual ~XglNodeEnd();

public:
	XglValue *execute();
};

