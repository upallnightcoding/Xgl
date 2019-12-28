#include "pch.h"
#include "XglCmdPrint.h"
#include "XglNodePrint.h"


XglCmdPrint::XglCmdPrint() : XglCmd("PRINT")
{
}


XglCmdPrint::~XglCmdPrint()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdPrint::execute(XglInterpreter *interpreter)
{
	XglNode *command = new XglNodePrint();

	XglToken *lastToken = new XglToken();

	while (!lastToken->isEos()) {
		XglNode *expression = interpreter->parseExpression();

		command->add(expression);

		lastToken = interpreter->getLastToken();
	}

	return(command);
}
