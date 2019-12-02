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

	XglToken *separator = new XglToken();

	while (!separator->isEos()) { 
		XglNode *attribute = interpreter->parseExpression();
		command->add(attribute);

		delete separator;
		separator = interpreter->getToken();
	}

	delete separator;

	return(command);
}
