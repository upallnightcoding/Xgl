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
XglNode *XglCmdEnd::execute(XglInterpreter *interpreter)
{
	interpreter->skipOver(XglTokenSymbolType::SYMBOL_SEMI);

	return(new XglNodeEnd());
}
