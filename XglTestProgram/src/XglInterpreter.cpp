#include "pch.h"
#include "XglInterpreter.h"
#include "XglNodeValue.h"

#include "XglCommandPrint.h"
#include "XglCommandProgram.h"
#include "XglCmdEnd.h"
#include "XglCmdConst.h"
#include "XglCmdDeclare.h"


XglInterpreter::XglInterpreter(XglProgram &program)
{
	this->program = program;

	add(new XglCommandPrint());
	add(new XglCommandProgram());
	add(new XglCmdEnd());
	add(new XglCmdConst());
	add(new XglCmdDeclare());
}


XglInterpreter::~XglInterpreter()
{
}

/*****************************************************************************
parseStatement() -
*****************************************************************************/
XglNode *XglInterpreter::parseStatement() 
{
	XglNode *node = NULL;

	XglToken *token = program.getToken();

	if (token != NULL) {
		string keyword = token->getString();

		if (!keyword.empty()) {
			XglCmd *command = commandMap[keyword];

			if (command != NULL) {
				node = command->execute(this);
			}
			else {
				//node = assign(keyword);
			}
		}
	}

	return(node);
}

XglToken *XglInterpreter::getToken()
{
	return(program.getToken());
}

XglNode *XglInterpreter::parseExpression()
{
	return(expression.parse(program));
}

XglToken *XglInterpreter::getLastToken()
{
	return(expression.getLastToken());
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglInterpreter::add(XglCmd *command)
{
	commandMap[command->getName()] = command;
}
