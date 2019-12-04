#pragma once
#include "XglNode.h"
#include "Xgl.h"
#include "XglProgram.h"

class XglExpression
{
public:
	XglExpression(XglProgram &program);
	virtual ~XglExpression();

public:
	XglNode *parse();

private:
	// Expression Stack
	stack<XglNode*> expStack;

	// Operator Stack
	stack<XglToken*> oprStack;

	XglProgram program;

};

