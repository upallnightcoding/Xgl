#include "pch.h"
#include "XglNodeNeg.h"


XglNodeNeg::XglNodeNeg() : XglNode(XglNodeType::NODE_NEG)
{
}


XglNodeNeg::~XglNodeNeg()
{
}

XglValue *XglNodeNeg::execute(XglContext &context)
{
	XglValue *target = evaluate(0, context);
	XglValue *value = NULL;

	switch (target->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(-target->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(-target->getReal());
		break;
	default:
		break;
	}

	return(value);
}
