#include "pch.h"
#include "XglCmdFor.h"
#include "XglNodeFor.h"
#include "XglNodeCodeBlock.h"

XglCmdFor::XglCmdFor() : XglCmd("FOR")
{
}


XglCmdFor::~XglCmdFor()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdFor::execute(XglInterpreter *interpreter)
{
	XglToken *type = interpreter->getToken();
	XglToken *variable = interpreter->getToken();

	interpreter->skipOver(XglTokenSymbolType::SYMBOL_EQ);

	XglNode *init = interpreter->parseExpression()->getExpression();
	XglNode *fin = interpreter->parseExpression()->getExpression();
	XglNode *step = interpreter->parseExpression()->getExpression();

	XglNode *codeBlock = new XglNodeCodeBlock();

	XglNode *statement = interpreter->parseStatement();

	while (!statement->isEnd()) {
		codeBlock->add(statement);
		statement = interpreter->parseStatement();
	}

	return(new XglNodeFor(type, variable, init, fin, step, codeBlock));
}