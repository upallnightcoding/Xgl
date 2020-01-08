#pragma once
#include "XglNode.h"
#include "Xgl.h"
#include "XglProgram.h"
#include "XglExpParse.h"

class XglExpression
{
public:
	XglExpression();
	virtual ~XglExpression();

public:
	XglExpParse *parse(XglProgram &program);

private:
	//XglNode *parse();
	void popOprStack(stack<XglToken*> &oprStack, stack<XglNode*> &expStack);
	void pushOperOnStack(XglToken *token, stack<XglToken*> &oprStack, stack<XglNode*> &expStack);
	void popUntilRightParen(stack<XglToken*> &oprStack, stack<XglNode*> &expStack);
	void emptyOprStack(stack<XglToken*> &oprStack, stack<XglNode*> &expStack);
	void pushKeywordOnExpStack(XglProgram &program, XglToken *token, stack<XglNode*> &expStack);
};

