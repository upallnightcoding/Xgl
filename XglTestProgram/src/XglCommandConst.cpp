#include "pch.h"
#include "XglCommandConst.h"
#include "XglNodeConst.h"
#include "XglNodeConstVar.h"

XglCommandConst::XglCommandConst() : XglCommand("CONST")
{
}


XglCommandConst::~XglCommandConst()
{
}

XglNode *XglCommandConst::execute(XglInterpreterAbstract *interpreter)
{
	XglNode *command = new XglNodeConst();

	XglToken *separator = NULL;
	XglToken *type = NULL;
	XglToken *variable = NULL;
	XglNode *expression = NULL;
	XglToken *equalSign = NULL;

	do {
		type = interpreter->getToken();
		variable = interpreter->getToken();
		equalSign = interpreter->getToken();
		expression = interpreter->parseExpression();

		command->add(new XglNodeConstVar(type, variable, expression));

		separator = interpreter->getLastToken();

	} while (!separator->isEos());

	return(command);
}
