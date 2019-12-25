#include "pch.h"
#include "XglNodeDivide.h"


XglNodeDivide::XglNodeDivide() : XglNode(XglNodeType::NODE_DIVIDE)
{
}


XglNodeDivide::~XglNodeDivide()
{
}

XglValue *XglNodeDivide::execute(XglContext *context)
{
	XglValue *value = NULL;

	XglValue *value1 = evaluate(0, context);
	XglValue *value2 = evaluate(1, context);

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() / value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() / value2->getReal());
		break;
	default:
		break;
	}

	return(value);
}
