#include "pch.h"
#include "XglInterpreter.h"
#include "XglNodeValue.h"

#include "XglCommandPrint.h"
#include "XglCommandProgram.h"
#include "XglCmdEnd.h"
#include "XglCmdConst.h"
#include "XglCmdDeclare.h"
#include "XglNodeAssign.h"


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
				node = assign(keyword);
			}
		}
	}

	return(node);
}

/*****************************************************************************
assign() - Creates the assignment node needed to set the value of an 
expression to a variable.  This functions skips over the assignment operator
and then parses the expression for later evaluation.
*****************************************************************************/
XglNode *XglInterpreter::assign(string keyword) 
{
	// Skip over assignment operator
	program.getToken();

	// Parse and assignment expression
	XglNode *value = parseExpression();

	// Define assignment node
	return(new XglNodeAssign(keyword, value));
}

/*****************************************************************************
getToken() -
*****************************************************************************/
XglToken *XglInterpreter::getToken()
{
	return(program.getToken());
}

/*****************************************************************************
parseExpression() -
*****************************************************************************/
XglNode *XglInterpreter::parseExpression()
{
	return(expression.parse(program));
}

/*****************************************************************************
getLastToken() -
*****************************************************************************/
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
