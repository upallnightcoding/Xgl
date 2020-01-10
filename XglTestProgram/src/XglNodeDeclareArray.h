#pragma once
#include "XglNode.h"

#include "XglToken.h"

class XglNodeDeclareArray :
	public XglNode
{
public:
	XglNodeDeclareArray(XglToken *type, XglToken *variable);
	virtual ~XglNodeDeclareArray();

public:
	void set(XglNode *initialize);
	XglValue *execute(XglContext *context);

private:
	int calcArraySize(XglContext *context);

private:
	XglToken *type;
	XglToken *variable;
	XglNode *initialize;
};

