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
XglNode *XglCmdDeclare::execute(XglSyntax *syntax)
{
	XglToken *separator = NULL;
	XglToken *type = NULL;
	XglToken *variable = NULL;
	XglNode *expression = NULL;

	XglNodeDeclare *command = new XglNodeDeclare();

	do {
		// Parse variable type and name
		//-----------------------------
		type = syntax->getInterpreter()->getToken();
		variable = syntax->getInterpreter()->getToken();
		
		separator = syntax->getInterpreter()->getToken();

		// Parse variable initialization expression
		//-----------------------------------------
		expression = NULL;
		if (separator->isAssignment()) {
			expression = syntax->getInterpreter()->parseExpression();
			separator = syntax->getInterpreter()->getLastToken();
		}

		// Capture variable declaration
		//-----------------------------
		command->add(new XglNodeDeclareVar(type, variable, expression));

	} while (!separator->isEos());

	return(command);
}
