#include "pch.h"
#include "XglCmdWhile.h"
#include "XglNodeCodeBlock.h"
#include "XglNodeWhile.h"
#include "XglExpParse.h"

XglCmdWhile::XglCmdWhile() : XglCmd("WHILE")
{
}


XglCmdWhile::~XglCmdWhile()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdWhile::execute(XglInterpreter *interpreter)
{
	XglExpParse *expression = interpreter->parseExpression();

	XglNode *codeBlock = new XglNodeCodeBlock();

	XglNode *statement = interpreter->parseStatement();

	while (!statement->isEnd()) {
		codeBlock->add(statement);
		statement = interpreter->parseStatement();
	}

	return(new XglNodeWhile(expression->getExpression(), codeBlock));
}
