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
XglNode *XglCmdDeclare::execute(XglInterpreter *interpreter)
{
	XglNodeDeclare *command = new XglNodeDeclare();

	XglToken *separator = NULL;
	XglToken *type = NULL;
	XglToken *variable = NULL;
	XglNode *expression = NULL;

	do {
		type = interpreter->getToken();
		variable = interpreter->getToken();
		expression = NULL;

		separator = interpreter->getToken();

		if (separator->isAssignment()) {
			expression = interpreter->parseExpression();
			separator = interpreter->getLastToken();
		}

		command->add(new XglNodeDeclareVar(type, variable, expression));

	} while (!separator->isEos());

	return(command);
}
