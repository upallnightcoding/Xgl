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

	XglToken *getEndToken();

private:
	//XglNode *parse();
	void popOprStack(stack<XglToken*> &oprStack, stack<XglNode*> &expStack);
	void pushOperOnStack(XglToken *token, stack<XglToken*> &oprStack, stack<XglNode*> &expStack);
	void popUntilRightParen(stack<XglToken*> &oprStack, stack<XglNode*> &expStack);
	void emptyOprStack(stack<XglToken*> &oprStack, stack<XglNode*> &expStack);
	void pushKeywordOnExpStack(XglToken *token, stack<XglNode*> &expStack);

private:
	XglProgram program;
	XglToken *lastToken;
};

