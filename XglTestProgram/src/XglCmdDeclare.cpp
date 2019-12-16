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
	XglToken *equalSign = NULL;

	do {
		type = interpreter->getToken();
		variable = interpreter->getToken();
		//equalSign = interpreter->getToken();
		//expression = interpreter->parseExpression();

		command->add(new XglNodeDeclareVar(type, variable, NULL));

		//separator = interpreter->getLastToken();
		separator = interpreter->getToken();

	} while (!separator->isEos());

	return(command);
}
