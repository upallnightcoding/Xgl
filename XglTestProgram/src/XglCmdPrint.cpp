#include "pch.h"
#include "XglCmdPrint.h"
#include "XglNodePrint.h"
#include "XglExpParse.h"

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
		XglExpParse *expression = interpreter->parseExpression();

		command->add(expression->getExpression());

		lastToken = expression->getLastToken();
	}

	return(command);
}
