#pragma once
#include "XglNode.h"
class XglNodeWhile :
	public XglNode
{
public:
	XglNodeWhile(XglNode *expression, XglNode *codeBlock);
	virtual ~XglNodeWhile();

public:
	XglValue *execute(XglContext *context);

private:
	XglNode *expression;
	XglNode *codeBlock;
};

