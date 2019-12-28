#include "pch.h"
#include "XglInterpreter.h"
#include "XglNodeValue.h"
#include "XglNodeTriplet.h"

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
	this->syntax = new XglSyntax(this);

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
				node = command->execute(syntax);
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
	XglNode *assignNode = NULL;

	// Skip over assignment operator
	program.getToken();

	// Parse and assignment expression
	XglNode *expression = parseExpression();

	if (getLastToken()->isQuestion()) {
		XglNode *truePart = parseExpression();
		XglNode *falsePart = parseExpression();

		assignNode = new XglNodeTriplet(expression, truePart, falsePart);
	}
	else {
		assignNode = expression;
	}

	// Define assignment node
	return(new XglNodeAssign(keyword, assignNode));
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
XglNode *XglInterpreter::parseExpression()
{
	return(expression.parse(program));
}

/*****************************************************************************
getLastToken() - Returns the last token that ended the parsing of an 
expression.  
*****************************************************************************/
XglToken *XglInterpreter::getLastToken()
{
	return(expression.getEndToken());
}

/*****************************************************************************
add() -
*****************************************************************************/
void XglInterpreter::add(XglCmd *command)
{
	commandMap[command->getName()] = command;
}
