#include "pch.h"
#include "XglExpression.h"


XglExpression::XglExpression(XglProgram &program)
{
	this->program = program;
}


XglExpression::~XglExpression()
{
}

XglNode *XglExpression::parse()
{
	int balance = 0;
	bool interpreting = true;

	while (interpreting) {
		XglToken *token = program.getToken();
	}

	return(NULL);
}
