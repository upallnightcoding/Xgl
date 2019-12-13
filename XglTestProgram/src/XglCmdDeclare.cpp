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

		command->add(new XglNodeDeclareVar(type, variable));

		separator = interpreter->getToken();

	} while (!separator->isEos());

	return(command);
}
