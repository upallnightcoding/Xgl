#pragma once
#include "XglNode.h"
class XglNodeAssign :
	public XglNode
{
public:
	XglNodeAssign(string variable, XglNode *expression);
	XglNodeAssign(XglToken *variable, XglNode *expression);
	virtual ~XglNodeAssign();

public:
	virtual XglValue *execute(XglContext *context);

private:
	string variable;
	XglNode *expression;
};

