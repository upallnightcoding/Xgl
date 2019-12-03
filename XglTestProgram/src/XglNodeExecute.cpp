#include "pch.h"
#include "XglNodeExecute.h"


XglNodeExecute::XglNodeExecute() 
	: XglNode(XglNodeType::NODE_EXEC)
{
}


XglNodeExecute::~XglNodeExecute()
{
}

XglValue *XglNodeExecute::execute()
{
	for (XglNode *attribute : getAttributes()) {
		attribute->evaluate();
	}

	return(NULL);
}
