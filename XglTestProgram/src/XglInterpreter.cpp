#include "pch.h"
#include "XglInterpreter.h"
#include "XglNodeValue.h"

#include "XglCommandPrint.h"
#include "XglCommandProgram.h"
#include "XglCommandEnd.h"


XglInterpreter::XglInterpreter(XglProgram &program)
{
	this->program = program;

	add(new XglCommandPrint());
	add(new XglCommandProgram());
	add(new XglCommandEnd());
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
			XglCommand *command = commandMap[keyword];

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
void XglInterpreter::add(XglCommand *command)
{
	commandMap[command->getName()] = command;
}
