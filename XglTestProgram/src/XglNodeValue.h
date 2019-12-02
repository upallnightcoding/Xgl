#pragma once
#include "XglNode.h"
#include "XglValue.h"
class XglNodeValue :
	public XglNode
{
public:
	XglNodeValue(XglValue *value);
	virtual ~XglNodeValue();

public:
	virtual XglValue *execute();

private:
	XglValue *value;
};

