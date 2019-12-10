#include "pch.h"
#include "XglNodeVariable.h"


XglNodeVariable::XglNodeVariable(XglValue *variable) : XglNode(XglNodeType::NODE_CONST_VARIABLE)
{
	this->variable = variable;
}

XglNodeVariable::~XglNodeVariable()
{
}

XglValue *XglNodeVariable::execute(XglContext &context)
{
	XglSymbolTable *symbolTable = context.getSymbolTable();

	XglValue *value = symbolTable->find(variable)->getValue(context);

	return(value);
}
