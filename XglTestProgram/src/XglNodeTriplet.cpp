#include "pch.h"
#include "XglNodeTriplet.h"


XglNodeTriplet::XglNodeTriplet(XglNode *expression, XglNode *truePart, XglNode *falsePart) 
	: XglNode(XglNodeType::NODE_TRIPLET)
{
	this->expression = expression;
	this->truePart = truePart;
	this->falsePart = falsePart;
}


XglNodeTriplet::~XglNodeTriplet()
{
}

/*****************************************************************************
execute() - 
*****************************************************************************/
XglValue *XglNodeTriplet::execute(XglContext *context)
{
	XglValue *triplet = NULL;

	if (expression->execute(context)->getBool()) {
		triplet = truePart->execute(context);
	}
	else {
		triplet = falsePart->execute(context);
	}

	return(triplet);
}
