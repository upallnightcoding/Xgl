#include "pch.h"
#include "XglNodeDeclare.h"


XglNodeDeclare::XglNodeDeclare() : XglNode(XglNodeType::NODE_DECLARE)
{
}


XglNodeDeclare::~XglNodeDeclare()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeDeclare::execute(XglContext &context)
{
	XglNode *command = NULL;

	return(NULL);
}
