#pragma once
#include "XglNode.h"
#include "XglValue.h"
#include "XglContext.h"

class XglNodeValue :
	public XglNode
{
public:
	XglNodeValue(XglValue *value);
	virtual ~XglNodeValue();

public:
	virtual XglValue *execute(XglContext &context);

private:
	XglValue *value;
};

