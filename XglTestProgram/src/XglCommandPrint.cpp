#include "pch.h"
#include "XglCommandPrint.h"
#include "XglNodePrint.h"


XglCommandPrint::XglCommandPrint() : XglCommand("PRINT")
{
}


XglCommandPrint::~XglCommandPrint()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCommandPrint::execute(XglInterpreterAbstract *interpreter)
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
