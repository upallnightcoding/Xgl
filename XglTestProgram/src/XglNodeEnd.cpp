#include "pch.h"
#include "XglNodeEnd.h"


XglNodeEnd::XglNodeEnd() : XglNode(XglNodeType::NODE_END)
{
}


XglNodeEnd::~XglNodeEnd()
{
}

XglValue *XglNodeEnd::execute(XglContext *context)
{
	return(NULL);
}
