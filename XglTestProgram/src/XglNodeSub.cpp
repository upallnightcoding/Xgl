#include "pch.h"
#include "XglNodeSub.h"


XglNodeSub::XglNodeSub() : XglNode(XglNodeType::NODE_SUB)
{
}


XglNodeSub::~XglNodeSub()
{
}

XglValue *XglNodeSub::execute(XglContext &context)
{
	XglValue *value = NULL;

	XglValue *value1 = evaluate(0, context);
	XglValue *value2 = evaluate(1, context);

	switch (value1->getType()) {
	case XglValueType::VALUE_INTEGER:
		value = new XglValue(value1->getInteger() - value2->getInteger());
		break;
	case XglValueType::VALUE_REAL:
		value = new XglValue(value1->getReal() - value2->getReal());
		break;
	default:
		break;
	}

	return(value);
}
