#pragma once
#include "XglNode.h"
class XglNodeFor :
	public XglNode
{
public:
	XglNodeFor(XglToken *type, XglToken *variable, XglNode *init, XglNode *fin, XglNode *step, XglNode *codeBlock);
	virtual ~XglNodeFor();

public:
	XglValue *execute(XglContext *context);

private:
	XglToken *type;
	XglToken *variable;

	XglNode *initialValue;
	XglNode *finalValue;
	XglNode *stepValue;
	XglNode *codeBlock;
};

