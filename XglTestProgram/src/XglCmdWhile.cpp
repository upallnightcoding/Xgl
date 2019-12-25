#include "pch.h"
#include "XglCmdWhile.h"
#include "XglNodeCodeBlock.h"
#include "XglNodeWhile.h"

XglCmdWhile::XglCmdWhile() : XglCmd("WHILE")
{
}


XglCmdWhile::~XglCmdWhile()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdWhile::execute(XglSyntax *syntax)
{
	XglNode *expression = syntax->getInterpreter()->parseExpression();

	XglNode *codeBlock = new XglNodeCodeBlock();

	XglNode *statement = syntax->getInterpreter()->parseStatement();

	while (!statement->isEnd()) {
		codeBlock->add(statement);
		statement = syntax->getInterpreter()->parseStatement();
	}

	return(new XglNodeWhile(expression, codeBlock));
}
