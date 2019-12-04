#include "pch.h"
#include "XglNodePrint.h"


XglNodePrint::XglNodePrint() : XglNode(XglNodeType::NODE_PRINT)
{
}


XglNodePrint::~XglNodePrint()
{
}

XglValue *XglNodePrint::execute(XglContext &context)
{
	for (XglNode *node : getCodeBlock()) {
		node->execute(context)->print();
	}

	cout << "\n";

	return(NULL);
}
