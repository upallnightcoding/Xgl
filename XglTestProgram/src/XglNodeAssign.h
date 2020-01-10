#pragma once
#include "XglNode.h"
#include "XglNodeAssignVar.h"

class XglNodeAssign :
	public XglNode
{
public:
	XglNodeAssign(XglNodeAssignVar *variable, XglNode *expression);
	XglNodeAssign(XglToken *variable, XglNode *expression);
	virtual ~XglNodeAssign();

public:
	virtual XglValue *execute(XglContext *context);

private:
	XglNodeAssignVar *variable;
	XglNode *value;
};

