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

/*****************************************************************************
getExpression() - Returns pointer to parsed expression.
*****************************************************************************/
XglNode *XglExpParse::getExpression()
{
	return(expression);
}

/*****************************************************************************
getLastToken() - Returns pointer to the token that halts an expression.
*****************************************************************************/
XglToken *XglExpParse::getLastToken()
{
	return(lastToken);
}