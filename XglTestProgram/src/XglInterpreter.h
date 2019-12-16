#pragma once

#include "Xgl.h"
#include "XglProgram.h"
#include "XglNode.h"
#include "XglExpression.h"

class XglCmd;

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
	XglNode *assign (string keyword);

private:
	void add(XglCmd *command);

private:
	XglProgram program;
	map<string, XglCmd*> commandMap;
	XglExpression expression;
};

#include "XglCmd.h"