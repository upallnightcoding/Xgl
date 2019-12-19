#pragma once
#include "XglNode.h"
class XglNodeFor :
	public XglNode
{
public:
	XglNodeFor(XglToken *type, XglToken *variable, XglNode *init, XglNode *fin, XglNode *step);
	virtual ~XglNodeFor();

public:
	XglValue *execute(XglContext &context);

private:
	XglToken *type;
	XglToken *variable;

	XglNode *init;
	XglNode *fin;
	XglNode *step;

	bool firstLoop;
};

