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
		XglValue *value = node->execute(context);
		value->print();
	}

	cout << "\n";

	return(NULL);
}
