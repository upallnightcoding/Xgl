#pragma once

#include "Xgl.h"
#include "XglProgram.h"
#include "XglNode.h"
#include "XglCommand.h"
#include "XglInterpreterAbstract.h"

class XglInterpreter : public XglInterpreterAbstract
{
public:
	XglInterpreter(XglProgram &program);
	virtual ~XglInterpreter();

public:
	XglNode *parseStatement();
	XglNode *parseExpression();

	XglToken *getToken();

private:
	void add(XglCommand *command);

private:
	XglProgram program;
	map<string, XglCommand*> commandMap;
};

