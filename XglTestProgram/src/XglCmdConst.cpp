#include "pch.h"
#include "XglCmdConst.h"
#include "XglNodeConst.h"
#include "XglNodeConstVar.h"

/*****************************************************************************
XglCmdConst() -
*****************************************************************************/
XglCmdConst::XglCmdConst() : XglCmd("CONST")
{
}

/*****************************************************************************
XglCmdConst() -
*****************************************************************************/
XglCmdConst::~XglCmdConst()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdConst::execute(XglInterpreter *interpreter)
{
	XglNode *command = new XglNodeConst();

	XglExpParse *expression = NULL;

	XglToken *separator = NULL;
	XglToken *type = NULL;
	XglToken *variable = NULL;
	XglToken *equalSign = NULL;

	do {
		type = interpreter->getToken();
		variable = interpreter->getToken();
		equalSign = interpreter->getToken();

		expression = interpreter->parseExpression();

		command->add(new XglNodeConstVar(type, variable, expression->getExpression()));

		separator = expression->getLastToken();

	} while (!separator->isEos());

	return(command);
}
