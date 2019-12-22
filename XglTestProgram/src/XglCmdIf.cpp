#include "pch.h"
#include "XglCmdIf.h"
#include "XglNodeIf.h"
#include "XglNodeCodeBlock.h"

XglCmdIf::XglCmdIf() : XglCmd("IF")
{
}


XglCmdIf::~XglCmdIf()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdIf::execute(XglInterpreter *interpreter)
{
	XglNodeIf *command = new XglNodeIf();
	XglNode *endingStatement = NULL;
	XglNode *codeBlock = NULL;
	XglNode *expression = NULL;

	IfCodeBlock ifCodeBlock = parseCodeBlock(interpreter, true);

	endingStatement = ifCodeBlock.endingStatement;
	expression = ifCodeBlock.expression;
	codeBlock = ifCodeBlock.codeBlock;

	command->add(expression, codeBlock);

	if (endingStatement->isElse()) {
		ifCodeBlock = parseCodeBlock(interpreter, false);
		codeBlock = ifCodeBlock.codeBlock;
		command->setElse(codeBlock);
	}

	return(command);
}

/*
XglNode *XglCmdIf::execute(XglInterpreter *interpreter)
{
	XglNodeIf *command = new XglNodeIf();
	XglNode *statement = NULL;
	XglNode *codeBlock = NULL;
	XglNode *expression = NULL;

	bool endOfIfStatement = false;

	IfCodeBlock ifCodeBlock = parseCodeBlock(interpreter, true);

	statement = ifCodeBlock.statement;
	expression = ifCodeBlock.expression;
	codeBlock = ifCodeBlock.codeBlock;

	command->add(expression, codeBlock);

	while (!endOfIfStatement) {
		if (statement->isEnd()) {
			endOfIfStatement = true;
		}
		else if (statement->isElse()) {
			ifCodeBlock = parseCodeBlock(interpreter, false);
			codeBlock = ifCodeBlock.codeBlock;
			command->setElse(codeBlock);
			endOfIfStatement = true;
		}
		else if (statement->isElseIf()) {
			ifCodeBlock = parseCodeBlock(interpreter, true);
			statement = ifCodeBlock.statement;
			expression = ifCodeBlock.expression;
			codeBlock = ifCodeBlock.codeBlock;
			command->add(expression, codeBlock);
		}
	}

	return(command);
}
*/

/*****************************************************************************
execute() -
*****************************************************************************/
IfCodeBlock XglCmdIf::parseCodeBlock(XglInterpreter *interpreter, bool parseExpression)
{
	XglNode *expression = NULL;

	if (parseExpression) {
		expression = interpreter->parseExpression();
	}

	XglNode *codeBlock = new XglNodeCodeBlock();

	XglNode *statement = interpreter->parseStatement();

	while (!statement->isEnd() && !statement->isElse() && !statement->isElseIf()) {
		codeBlock->add(statement);
		statement = interpreter->parseStatement();
	}

	return(IfCodeBlock(statement, expression, codeBlock));
}

IfCodeBlock::IfCodeBlock(XglNode *statement, XglNode *expression, XglNode *codeBlock)
{
	this->endingStatement = statement;
	this->expression = expression;
	this->codeBlock = codeBlock;
}

/*
while (!endOfIfStatement) {
		expression = interpreter->parseExpression();

		codeBlock = new XglNodeCodeBlock();

		statement = interpreter->parseStatement();

		while (!statement->isEnd() && !statement->isElse() && !statement->isElseIf()) {
			codeBlock->add(statement);
			statement = interpreter->parseStatement();
		}

		if (statement->isEnd()) {
			command->add(expression, codeBlock);
			endOfIfStatement = true;
		}

		if (statement->isElse()) {

		}
	}
*/