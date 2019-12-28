#include "pch.h"
#include "XglCmdElse.h"
#include "XglNodeElse.h"

XglCmdElse::XglCmdElse() : XglCmd("ELSE")
{
}

XglCmdElse::~XglCmdElse()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdElse::execute(XglSyntax *syntax)
{
	syntax->getInterpreter()->skipOver(XglTokenSymbolType::SYMBOL_SEMI);

	return(new XglNodeElse());
}