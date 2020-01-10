#pragma once
#include "XglNode.h"
#include "XglToken.h"

class XglNodeDeclareVar :
	public XglNode
{
public:
	XglNodeDeclareVar(XglToken *type, XglToken *variable, XglNode *initialize);
	XglNodeDeclareVar(XglToken *type, XglToken *variable);
	virtual ~XglNodeDeclareVar();

public:
	XglValue *execute(XglContext *context);
	void set(XglNode *expression);

private:
	XglToken *type;
	XglToken *variable;
	XglNode *initialize;
};

