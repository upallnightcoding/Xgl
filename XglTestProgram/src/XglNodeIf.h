#pragma once
#include "XglNode.h"

class XglNodeIf :
	public XglNode
{
public:
	XglNodeIf();
	virtual ~XglNodeIf();

public:
	void add(XglNode *expression, XglNode *codeBlock);

	XglValue *execute(XglContext &context);

	void setElse(XglNode *codeBlock);

private:
	int nIfs;
	XglNode *elseStatement;

	XglNode *expressions[10];
	XglNode *codeBlocks[10];
};

