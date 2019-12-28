#pragma once

#include "Xgl.h"
#include "XglProgram.h"
#include "XglNode.h"
#include "XglExpression.h"

class XglCmd;
class XglSyntax;

class XglInterpreter 
{
public:
	XglInterpreter(XglProgram &program);
	virtual ~XglInterpreter();

public:
	virtual XglToken *getLastToken();

	XglNode *parseStatement();
	XglNode *parseExpression();

	XglToken *getToken();
	bool skipOver(XglTokenSymbolType symbol);
	XglNode *assign (string keyword);

private:
	void add(XglCmd *command);

private:
	XglProgram program;
	map<string, XglCmd*> commandMap;
	XglExpression expression;
	XglSyntax *syntax;
};

#include "XglCmd.h"