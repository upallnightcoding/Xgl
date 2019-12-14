#include "pch.h"
#include "XglCmdDeclare.h"
#include "XglNodeDeclare.h"
#include "XglNodeDeclareVar.h"


XglCmdDeclare::XglCmdDeclare() : XglCmd("DECLARE")
{
}


XglCmdDeclare::~XglCmdDeclare()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdDeclare::execute(XglInterpreterAbstract *interpreter)
{
	XglNodeDeclare *command = new XglNodeDeclare();

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

		command->add(new XglNodeDeclareVar(type, variable, expression));

		separator = interpreter->getLastToken();

	} while (!separator->isEos());

	return(command);
}
