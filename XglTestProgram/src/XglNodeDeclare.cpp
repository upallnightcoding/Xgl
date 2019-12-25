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
XglValue *XglNodeDeclare::execute(XglContext *context)
{
	for (XglNode *node : getAttributes()) {
		node->execute(context);
	}

	return(NULL);
}
