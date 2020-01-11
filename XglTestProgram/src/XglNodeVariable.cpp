#include "pch.h"
#include "XglNodeVariable.h"


XglNodeVariable::XglNodeVariable(XglValue *variable) : XglNode(XglNodeType::NODE_VARIABLE)
{
	this->variable = variable;
}

XglNodeVariable::~XglNodeVariable()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeVariable::execute(XglContext *context)
{
	XglValue *value = NULL;
	int index = 0;

	XglSymbolTable *symbolTable = context->getSymbolTable();
	XglSymbolTableRec *record = symbolTable->find(variable);

	if ((record != NULL) && (record->isArray())) {
		index = evaluate(0, context)->getInteger();
	}

	value = record->access(index, context);

	return(value);
}
