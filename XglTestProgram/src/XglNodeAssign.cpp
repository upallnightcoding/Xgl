#include "pch.h"
#include "XglNodeAssign.h"


XglNodeAssign::XglNodeAssign(string variable, XglNode *expression) : XglNode(XglNodeType::NODE_ASSIGN)
{
	this->variable = variable;
	this->expression = expression;
}


XglNodeAssign::~XglNodeAssign()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeAssign::execute(XglContext &context)
{
	XglValue *value = expression->execute(context);

	XglSymbolTableRec *record = context.getSymbolTable()->find(variable);

	if (record != NULL) {
		record->getData()->assign(0, value);
	}

	return(NULL);
}
