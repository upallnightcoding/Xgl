#include "pch.h"
#include "XglCmdDeclare.h"
#include "XglNodeDeclare.h"
#include "XglNodeDeclareVar.h"
#include "XglNodeDeclareArray.h"

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
	XglNodeDeclare *command = new XglNodeDeclare();

	do {
		// Parse variable type and name
		//-----------------------------
		XglToken *type = interpreter->getToken();
		XglToken *variable = interpreter->getToken();

		separator = interpreter->getToken();

		// If therer is a left bracket, capture array declaration
		//-------------------------------------------------------
		if (separator->isLeftBracket()) {
			XglNodeDeclareArray *declareVar = new XglNodeDeclareArray(type, variable);
			interpreter->parseArray(declareVar);
			command->add(declareVar);
			separator = interpreter->getToken();  
		}
		// Capture scalar variable with possible initialization
		//-----------------------------------------------------
		else {
			XglNodeDeclareVar *declareVar = new XglNodeDeclareVar(type, variable);

			if (separator->isAssignment()) {
				XglExpParse *initialize = interpreter->parseExpression();
				declareVar->set(initialize->getExpression());
				separator = initialize->getLastToken();
			}

			command->add(declareVar);
		}

	} while (!separator->isEos());

	return(command);
}
