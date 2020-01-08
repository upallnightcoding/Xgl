#pragma once
#include "XglNode.h"

#include "XglToken.h"

class XglNodeDeclareArray :
	public XglNode
{
public:
	XglNodeDeclareArray(XglToken *type, XglToken *variable, XglNode *arraySize);
	virtual ~XglNodeDeclareArray();

public:
	XglValue *execute(XglContext *context);

private:
	XglToken *type;
	XglToken *variable;
	XglNode *arraySize;
};

