#include "pch.h"
#include "XglNodePrint.h"


XglNodePrint::XglNodePrint() : XglNode(XglNodeType::NODE_PRINT)
{
}


XglNodePrint::~XglNodePrint()
{
}

XglValue *XglNodePrint::execute()
{
	for (XglNode *node : getAttributes()) {
		node->execute()->print();
	}

	cout << "\n";

	return(NULL);
}
