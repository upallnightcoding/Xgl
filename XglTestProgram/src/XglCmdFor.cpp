#include "pch.h"
#include "XglCmdFor.h"
#include "XglNodeFor.h"

XglCmdFor::XglCmdFor() : XglCmd("FOR")
{
}


XglCmdFor::~XglCmdFor()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdFor::execute(XglInterpreter *interpreter)
{
	XglToken *type = interpreter->getToken();
	XglToken *variable = interpreter->getToken();

	interpreter->skipOver();

	XglNode *init = interpreter->parseExpression();
	XglNode *fin = interpreter->parseExpression();
	XglNode *step = interpreter->parseExpression();

	return(new XglNodeFor(type, variable, init, fin, step));
}