#pragma once
#include "XglNode.h"
class XglNodePrint :
	public XglNode
{
public:
	XglNodePrint();
	virtual ~XglNodePrint();

public:
	virtual XglValue *execute();
};

