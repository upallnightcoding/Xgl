#include "pch.h"
#include "XglNodeValue.h"


XglNodeValue::XglNodeValue(XglValue *value)
{
	this->value = value;
}


XglNodeValue::~XglNodeValue()
{
}

XglValue *XglNodeValue::execute()
{
	return(value);
}
