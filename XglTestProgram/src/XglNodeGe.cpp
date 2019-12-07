#include "pch.h"
#include "XglNodeGe.h"


XglNodeGe::XglNodeGe() : XglNode(XglNodeType::NODE_GE)
{
}


XglNodeGe::~XglNodeGe()
{
}

XglValue *XglNodeGe::execute(XglContext &context)
{
	XglValue *value = NULL;

	XglValue *value1 = evaluate(0, context);
	XglValue *value2 = evaluate(1, context);

	switch (value1->getType()) {
	case XglValueType::VALUE_INTEGER:
		value = new XglValue(value1->getInteger() >= value2->getInteger());
		break;
	case XglValueType::VALUE_REAL:
		value = new XglValue(value1->getReal() >= value2->getReal());
		break;
	case XglValueType::VALUE_STRING:
		value = new XglValue(value1->getString() >= value2->getString());
		break;
	case XglValueType::VALUE_BOOLEAN:
		value = new XglValue(value1->getBool() >= value2->getBool());
		break;
	default:
		break;
	}

	return(value);
}
