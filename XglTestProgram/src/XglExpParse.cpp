#include "pch.h"
#include "XglExpParse.h"


XglExpParse::XglExpParse(XglNode *expression, XglToken *lastToken)
{
	this->expression = expression;
	this->lastToken = lastToken;
}

XglExpParse::~XglExpParse()
{
}

XglNode *XglExpParse::getExpression()
{
	return(expression);
}

XglToken *XglExpParse::getLastToken()
{
	return(lastToken);
}