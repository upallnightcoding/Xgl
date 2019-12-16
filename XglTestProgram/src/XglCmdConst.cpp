#include "pch.h"
#include "XglCmdConst.h"
#include "XglNodeConst.h"
#include "XglNodeConstVar.h"

XglCmdConst::XglCmdConst() : XglCmd("CONST")
{
}


XglCmdConst::~XglCmdConst()
{
}

XglNode *XglCmdConst::execute(XglInterpreter *interpreter)
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