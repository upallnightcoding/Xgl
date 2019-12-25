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
XglNode *XglCmdFor::execute(XglSyntax *syntax)
{
	XglInterpreter *interpreter = syntax->getInterpreter();

	XglToken *type = interpreter->getToken();
	XglToken *variable = interpreter->getToken();

	interpreter->skipOver();

	XglNode *init = interpreter->parseExpression();
	XglNode *fin = interpreter->parseExpression();
	XglNode *step = interpreter->parseExpression();

	XglNode *codeBlock = new XglNodeCodeBlock();

	XglNode *statement = interpreter->parseStatement();

	while (!statement->isEnd()) {
		codeBlock->add(statement);
		statement = interpreter->parseStatement();
	}

	return(new XglNodeFor(type, variable, init, fin, step, codeBlock));
}