#include "pch.h"
#include "XglCommandPrint.h"
#include "XglNodePrint.h"


XglCommandPrint::XglCommandPrint() : XglCommand("PRINT")
{
}


XglCommandPrint::~XglCommandPrint()
{
}

XglNode *XglCommandPrint::execute(XglInterpreterAbstract *interpreter)
{
	XglNode *command = new XglNodePrint();

	XglToken *lastToken = new XglToken();

	while (!lastToken->isEos()) {
		XglNode *attribute = interpreter->parseExpression();

		command->add(attribute);

		lastToken = interpreter->getLastToken();
	}

	return(command);
}
