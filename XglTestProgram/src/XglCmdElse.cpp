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
XglNode *XglCmdElse::execute(XglInterpreter *interpreter)
{
	interpreter->skipOver(XglTokenSymbolType::SYMBOL_SEMI);

	return(new XglNodeElse());
}