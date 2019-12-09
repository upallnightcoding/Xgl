#include "pch.h"
#include "XglNodePrint.h"


XglNodePrint::XglNodePrint() : XglNode(XglNodeType::NODE_PRINT)
{
}


XglNodePrint::~XglNodePrint()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodePrint::execute(XglContext &context)
{
	for (XglNode *node : getChildren()) {

		XglValue *value = node->execute(context);

		value->print();
	}

	cout << "\n";

	return(NULL);
}
