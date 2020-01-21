#include "pch.h"
#include "XglNodeUnaryOperator.h"

/*****************************************************************************
XglNodeUnaryOperator()
*****************************************************************************/
XglNodeUnaryOperator::XglNodeUnaryOperator(XglNodeType type) : XglNode(type)
{
	this->type = type;
	this->argument = NULL;
}

/*****************************************************************************
~XglNodeUnaryOperator()
*****************************************************************************/
XglNodeUnaryOperator::~XglNodeUnaryOperator()
{
	delete argument;
}

/*****************************************************************************
execute() - Executes a unary operator node.  The node must have one argument.
Any other arguments will be ignored.  The resulting value depends on the 
node action taken.
*****************************************************************************/
XglValue *XglNodeUnaryOperator::execute(XglContext *context)
{
	XglValue *value = NULL;

	argument = evaluate(0, context);

	switch (type) {
	case XglNodeType::NODE_NEG:
		value = neg(context, argument);
		break;
	case XglNodeType::NODE_NOT:
		value = nott(context, argument);
		break;
	}

	return(value);
}

/*****************************************************************************
nott() - Evaluates the current node to a boolean and negates the result.  If
the result is a true, it is converted to false.  If the value is false, it 
is converted to true.
*****************************************************************************/
XglValue *XglNodeUnaryOperator::nott(XglContext *context, XglValue *argument)
{
	return(new XglValue(!evaluate(0, context)->getBool()));
}

/*****************************************************************************
neg() - Evaluates the node to a real or integer value and flips the +/- sign.
If the value is positive it is converted to negative.  If the value is 
negative, it is converted to positive.
*****************************************************************************/
XglValue *XglNodeUnaryOperator::neg(XglContext *context, XglValue *argument)
{
	XglValue *value = NULL;

	switch (argument->getType()) {
	case XglValueType::INTEGER:
		value = new XglValue(-argument->getInteger());
		break;
	case XglValueType::REAL:
		value = new XglValue(-argument->getReal());
		break;
	}

	return(value);
}
