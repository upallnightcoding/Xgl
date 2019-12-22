#include "pch.h"
#include "XglNodeElseIf.h"


XglNodeElseIf::XglNodeElseIf() : XglNode(XglNodeType::NODE_ELSEIF)
{
}


XglNodeElseIf::~XglNodeElseIf()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeElseIf::execute(XglContext &context)
{
	return(NULL);
}
