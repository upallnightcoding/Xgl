#pragma once
#include "XglCmd.h"

class IfCodeBlock
{
public:
	IfCodeBlock(XglNode *statement, XglNode *expression, XglNode *codeBlock);

public:
	XglNode *expression;
	XglNode *codeBlock;
	XglNode *endingStatement;
};

class XglCmdIf :
	public XglCmd
{
public:
	XglCmdIf();
	virtual ~XglCmdIf();

public:
	XglNode *execute(XglInterpreter *interpreter);

private:
	IfCodeBlock parseCodeBlock(XglInterpreter *interpreter, bool parseExpression);
};

