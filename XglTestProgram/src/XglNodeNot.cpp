#include "pch.h"
#include "XglNodeNot.h"


XglNodeNot::XglNodeNot() : XglNode(XglNodeType::NODE_NOT)
{
}


XglNodeNot::~XglNodeNot()
{
}

XglValue *XglNodeNot::execute(XglContext &context)
{
	return(new XglValue(!evaluate(0, context)->getBool()));
}
