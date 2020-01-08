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
	XglToken *separator = NULL;
	XglToken *type = NULL;
	XglToken *variable = NULL;
	XglExpParse *expression = NULL;

	XglNodeDeclare *command = new XglNodeDeclare();

	do {
		// Parse variable type and name
		//-----------------------------
		type = interpreter->getToken();
		variable = interpreter->getToken();
		
		separator = interpreter->getToken();

		// Parse variable initialization expression
		//-----------------------------------------
		expression = NULL;
		if (separator->isAssignment()) {
			expression = interpreter->parseExpression();
			separator = expression->getLastToken();
		}

		// Capture variable declaration
		//-----------------------------
		command->add(new XglNodeDeclareVar(type, variable, expression->getExpression()));

	} while (!separator->isEos());

	return(command);
}
