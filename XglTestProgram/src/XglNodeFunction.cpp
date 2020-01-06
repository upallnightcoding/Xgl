#include "pch.h"
#include "XglNodeFunction.h"


XglNodeFunction::XglNodeFunction() : XglNode(XglNodeType::NODE_FUNCTION)
{
}


XglNodeFunction::~XglNodeFunction()
{
}

XglValue *XglNodeFunction::execute(XglContext *context)
{
	return(NULL);
}
