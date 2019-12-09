#include "pch.h"
#include "XglNodeConst.h"


XglNodeConst::XglNodeConst() : XglNode(XglNodeType::NODE_CONST)
{
}


XglNodeConst::~XglNodeConst()
{
}

XglValue *XglNodeConst::execute(XglContext &context)
{
	for (XglNode *node : getChildren()) {
		node->execute(context);
	}

	return(NULL);
}
