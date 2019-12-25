#include "pch.h"
#include "XglNodeConst.h"


XglNodeConst::XglNodeConst() : XglNode(XglNodeType::NODE_CONST)
{
}


XglNodeConst::~XglNodeConst()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeConst::execute(XglContext *context)
{
	for (XglNode *node : getAttributes()) {
		node->execute(context);
	}

	return(NULL);
}
