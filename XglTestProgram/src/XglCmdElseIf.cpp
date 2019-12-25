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
XglNode *XglCmdElseIf::execute(XglSyntax *syntax)
{
	syntax->getInterpreter()->skipOver();

	return(NULL);
}