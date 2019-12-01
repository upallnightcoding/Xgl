#pragma once

#include "XglProgram.h"
#include "XglNode.h"

class XglInterpreter
{
public:
	XglInterpreter(XglProgram &program);
	virtual ~XglInterpreter();

public:
	XglNode *parseExpression();

private:
	XglProgram program;
};

