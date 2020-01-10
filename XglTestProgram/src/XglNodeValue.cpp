#include "pch.h"
#include "XglNodeValue.h"


XglNodeValue::XglNodeValue(XglValue *value) 
	: XglNode(XglNodeType::NODE_VALUE)
{
	this->value = value;
}


XglNodeValue::~XglNodeValue()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeValue::execute(XglContext *context)
{
	return(value);
}
