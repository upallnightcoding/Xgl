#pragma once

#include "Xgl.h"
#include "XglProgram.h"
#include "XglNode.h"
#include "XglCmd.h"
#include "XglInterpreterAbstract.h"
#include "XglExpression.h"

class XglInterpreter : public XglInterpreterAbstract
{
public:
	XglInterpreter(XglProgram &program);
	virtual ~XglInterpreter();

public:
	virtual XglToken *getLastToken();

	XglNode *parseStatement();
	XglNode *parseExpression();

	XglToken *getToken();

private:
	void add(XglCmd *command);

private:
	XglProgram program;
	map<string, XglCmd*> commandMap;
	XglExpression expression;
};

