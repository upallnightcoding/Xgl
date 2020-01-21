#include "pch.h"
#include "XglNodeBinaryOperator.h"


XglNodeBinaryOperator::XglNodeBinaryOperator(XglNodeType type) : XglNode(type)
{
	this->type = type;
	this->value1 = NULL;
	this->value2 = NULL;
}

XglNodeBinaryOperator::~XglNodeBinaryOperator()
{
	delete value1;
	delete value2;
}

XglValue *XglNodeBinaryOperator::execute(XglContext *context)
{
	XglValue *value = NULL;

	value1 = evaluate(0, context);
	value2 = evaluate(1, context);

	switch (type) {
	case XglNodeType::NODE_ADD:
		value = add(context, value1, value2);
		break;
	case XglNodeType::NODE_DIVIDE:
		value = divide(context, value1, value2);
		break;
	case XglNodeType::NODE_MULT:
		value = multi(context, value1, value2);
		break;
	case XglNodeType::NODE_SUB:
		value = sub(context, value1, value2);
		break;
	case XglNodeType::NODE_GE:
		value = ge(context, value1, value2);
		break;
	case XglNodeType::NODE_NE:
		value = ne(context, value1, value2);
		break;
	case XglNodeType::NODE_EQ:
		value = eq(context, value1, value2);
		break;
	case XglNodeType::NODE_GT:
		value = gt(context, value1, value2);
		break;
	case XglNodeType::NODE_LT:
		value = lt(context, value1, value2);
		break;
	case XglNodeType::NODE_LE:
		value = le(context, value1, value2);
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::le(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() <= value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() <= value2->getReal());
		break;
	case XglValueType::STRING:
		value = new XglValue(value1->getString() <= value2->getString());
		break;
	case XglValueType::BOOLEAN:
		value = new XglValue(value1->getBool() <= value2->getBool());
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::lt(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() < value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() < value2->getReal());
		break;
	case XglValueType::STRING:
		value = new XglValue(value1->getString() < value2->getString());
		break;
	case XglValueType::BOOLEAN:
		value = new XglValue(value1->getBool() < value2->getBool());
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::gt(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() > value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() > value2->getReal());
		break;
	case XglValueType::STRING:
		value = new XglValue(value1->getString() > value2->getString());
		break;
	case XglValueType::BOOLEAN:
		value = new XglValue(value1->getBool() > value2->getBool());
		break;
	default:
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::eq(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() == value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() == value2->getReal());
		break;
	case XglValueType::STRING:
		value = new XglValue(value1->getString() == value2->getString());
		break;
	case XglValueType::BOOLEAN:
		value = new XglValue(value1->getBool() == value2->getBool());
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::ne(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() != value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() != value2->getReal());
		break;
	case XglValueType::STRING:
		value = new XglValue(value1->getString() != value2->getString());
		break;
	case XglValueType::BOOLEAN:
		value = new XglValue(value1->getBool() != value2->getBool());
		break;
	default:
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::ge(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() >= value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() >= value2->getReal());
		break;
	case XglValueType::STRING:
		value = new XglValue(value1->getString() >= value2->getString());
		break;
	case XglValueType::BOOLEAN:
		value = new XglValue(value1->getBool() >= value2->getBool());
		break;
	default:
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::divide(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

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

XglValue *XglNodeBinaryOperator::multi(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() * value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() * value2->getReal());
		break;
	default:
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::add(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() + value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() + value2->getReal());
		break;
	case XglValueType::STRING:
		value = new XglValue(value1->getString() + value2->getString());
		break;
	case XglValueType::BOOLEAN:
		value = new XglValue(value1->getBool() && value2->getBool());
		break;
	default:
		break;
	}

	return(value);
}

XglValue *XglNodeBinaryOperator::sub(XglContext *context, XglValue *value1, XglValue *value2)
{
	XglValue *value = NULL;

	switch (value1->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(value1->getInteger() - value2->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(value1->getReal() - value2->getReal());
		break;
	default:
		break;
	}

	return(value);
}
