#include "pch.h"
#include "XglNodeElse.h"


XglNodeElse::XglNodeElse() : XglNode(XglNodeType::NODE_ELSE)
{
}


XglNodeElse::~XglNodeElse()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeElse::execute(XglContext *context)
{
	return(NULL);
}

