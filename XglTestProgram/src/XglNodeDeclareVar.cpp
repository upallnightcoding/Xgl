#include "pch.h"
#include "XglNodeDeclareVar.h"


XglNodeDeclareVar::XglNodeDeclareVar(XglToken *type, XglToken *variable, XglNode *expression) : XglNode(XglNodeType::NODE_DECLARE_VARIABLE)
{
	this->type = type;
	this->variable = variable;
	this->expression = expression;
}


XglNodeDeclareVar::~XglNodeDeclareVar()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeDeclareVar::execute(XglContext &context)
{
	XglSymbolTable *symbolTable = context.getSymbolTable();

	symbolTable->add(type, variable, 1, expression);

	return(NULL);
}
