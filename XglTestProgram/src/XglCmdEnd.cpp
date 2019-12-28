#include "pch.h"
#include "XglCmdEnd.h"
#include "XglNodeEnd.h"


XglCmdEnd::XglCmdEnd() : XglCmd("END")
{
}


XglCmdEnd::~XglCmdEnd()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdEnd::execute(XglSyntax *syntax)
{
	syntax->getInterpreter()->skipOver(XglTokenSymbolType::SYMBOL_SEMI);

	return(new XglNodeEnd());
}
