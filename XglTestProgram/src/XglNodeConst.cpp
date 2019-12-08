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
	return(NULL);
}
