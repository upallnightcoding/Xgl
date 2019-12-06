#pragma once
#include "XglNode.h"
#include "Xgl.h"
#include "XglProgram.h"

class XglExpression
{
public:
	XglExpression();
	virtual ~XglExpression();

public:
	XglNode *parse(XglProgram &program);

	XglToken *getLastToken();

private:
	//XglNode *parse();
	void popOprStack();
	void pushOperOnStack(XglToken *token);
	void popUntilRightParen();
	void emptyOprStack();

private:
	// Expression Stack
	stack<XglNode*> expStack;

	// Operator Stack
	stack<XglToken*> oprStack;

	XglToken *lastToken;
	XglProgram program;
};

