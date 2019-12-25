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
XglNode *XglCmdPrint::execute(XglSyntax *syntax)
{
	XglNode *command = new XglNodePrint();

	XglToken *lastToken = new XglToken();

	while (!lastToken->isEos()) {
		XglNode *expression = syntax->getInterpreter()->parseExpression();

		command->add(expression);

		lastToken = syntax->getInterpreter()->getLastToken();
	}

	return(command);
}
