#include "pch.h"
#include "XglInterpreter.h"
#include "XglNodeValue.h"
#include "XglNodeTriplet.h"
#include "XglNodeAssignVar.h"

#include "XglCmdPrint.h"
#include "XglCmdProgram.h"
#include "XglCmdEnd.h"
#include "XglCmdConst.h"
#include "XglCmdDeclare.h"
#include "XglNodeAssign.h"
#include "XglCmdWhile.h"
#include "XglCmdFor.h"
#include "XglCmdIf.h"
#include "XglCmdElse.h"
#include "XglCmdElseIf.h"


XglInterpreter::XglInterpreter(XglProgram &program)
{
	this->program = program;
	this->nErrors = 0;

	add(new XglCmdPrint());
	add(new XglCmdProgram());
	add(new XglCmdEnd());
	add(new XglCmdConst());
	add(new XglCmdDeclare());
	add(new XglCmdWhile());
	add(new XglCmdFor());
	add(new XglCmdIf());
	add(new XglCmdElse());
	add(new XglCmdElseIf());
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
parseArray() -
*****************************************************************************/
void XglInterpreter::parseArray(XglNode *arrayVariable)
{
	XglExpParse *argument = NULL;

	do {
		argument = parseExpression();
		arrayVariable->add(argument->getExpression());
	} while (!argument->getLastToken()->isRightBracket());
}

/*****************************************************************************
assign() - Creates the assignment node needed to set the value of an 
expression to a variable.  This functions skips over the assignment operator
and then parses the expression for later evaluation.
*****************************************************************************/
XglNode *XglInterpreter::assign(string variableName) 
{
	XglNode *value = NULL;

	XglNodeAssignVar *variable = new XglNodeAssignVar(variableName);

	// Skip over assignment operator
	XglToken *separator = program.getToken();

	if (separator->isLeftBracket()) {
		parseArray(variable);
		separator = program.getToken();
	}

	// Parse and assignment expression
	XglExpParse *expression = parseExpression();

	if (expression->getLastToken()->isQuestion()) {
		XglNode *truePart = parseExpression()->getExpression();
		XglNode *falsePart = parseExpression()->getExpression();

		value = new XglNodeTriplet(expression->getExpression(), truePart, falsePart);
	}
	else {
		value = expression->getExpression();
	}

	// Define assignment node
	return(new XglNodeAssign(variable, value));
}

/*****************************************************************************
getToken() - Returns a pointer to the next source token object.
*****************************************************************************/
XglToken *XglInterpreter::getToken()
{
	return(program.getToken());
}

/*****************************************************************************
skipOver() - 
*****************************************************************************/
bool XglInterpreter::skipOver(XglTokenSymbolType symbol)
{
	XglToken *token = program.getToken();

	bool check = token->is(symbol);

	delete token;

	return(check);
}

/*****************************************************************************
parseExpression() - Parses the next full expression and returns a pointer
to a node representing the expression.
*****************************************************************************/
XglExpParse *XglInterpreter::parseExpression()
{
	return(expression.parse(program));
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglInterpreter::add(XglCmd *command)
{
	commandMap[command->getName()] = command;
}

/*****************************************************************************
getErrorMessage() -
*****************************************************************************/
string XglInterpreter::getErrorMessage(XglErrorMessageType type)
{
	string msg = "";

	switch (type) {
	case XglErrorMessageType::EOS_EXPECTED:
		msg = "End of statement was expected but not found.";
		break;
	}

	return(msg);
}

/*****************************************************************************
error() -
*****************************************************************************/
void XglInterpreter::error(XglErrorMessageType type)
{
	nErrors++; 

	cout << program.getErrorLine() << "\n";
	cout << "Error: " << getErrorMessage(type) << "\n";
}

/*****************************************************************************
isNoErrors() -
*****************************************************************************/
bool XglInterpreter::isNoErrors()
{
	return(nErrors == 0);
}

/*****************************************************************************
getnErrors() -
*****************************************************************************/
int XglInterpreter::getnErrors()
{
	return(nErrors);
}