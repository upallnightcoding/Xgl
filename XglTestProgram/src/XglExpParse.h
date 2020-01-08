#pragma once

#include "XglNode.h"
#include "XglToken.h"

class XglExpParse
{
public:
	XglExpParse(XglNode *expression, XglToken *lastToken);
	virtual ~XglExpParse();

public:
	XglNode *getExpression();
	XglToken *getLastToken();

private:
	XglNode *expression;
	XglToken *lastToken;
};

