#include "pch.h"
#include "XglCmdElseIf.h"


XglCmdElseIf::XglCmdElseIf() : XglCmd("ELSEIF")
{
}


XglCmdElseIf::~XglCmdElseIf()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdElseIf::execute(XglInterpreter *interpreter)
{
	interpreter->skipOver(XglTokenSymbolType::SYMBOL_SEMI);

	return(NULL);
}