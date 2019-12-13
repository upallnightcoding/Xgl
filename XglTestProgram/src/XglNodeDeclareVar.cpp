#include "pch.h"
#include "XglNodeDeclareVar.h"


XglNodeDeclareVar::XglNodeDeclareVar(XglToken *type, XglToken *variable) : XglNode(XglNodeType::NODE_DECLARE_VARIABLE)
{
	this->type = type;
	this->variable = variable;
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

	symbolTable->add(type, variable);

	return(NULL);
}
