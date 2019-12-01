#include "pch.h"
#include "XglInterpreter.h"


XglInterpreter::XglInterpreter(XglProgram &program)
{
	this->program = program;
}


XglInterpreter::~XglInterpreter()
{
}

XglNode *XglInterpreter::parseExpression()
{
	XglNode *node = NULL;
	bool interpreting = true;

	while (interpreting) {
		XglToken *token = program.getToken();
	}

	return(node);
}
