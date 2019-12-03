#pragma once
#include "XglNode.h"
class XglNodeExecute :
	public XglNode
{
public:
	XglNodeExecute();
	virtual ~XglNodeExecute();

public:
	virtual XglValue *execute();
};

