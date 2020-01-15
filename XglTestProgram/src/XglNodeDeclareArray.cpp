#include "pch.h"
#include "XglNodeDeclareArray.h"


XglNodeDeclareArray::XglNodeDeclareArray(XglToken *type, XglToken *variable)
	: XglNode(XglNodeType::NODE_DECLARE_ARRAY)
{
	this->type = type;
	this->variable = variable;
	this->initialize = NULL;
}

XglNodeDeclareArray::~XglNodeDeclareArray()
{
}

/*****************************************************************************
set() - Sets the value that will be used to initialize the variable upon
declaration.  If there is no initialization, the initialize value should be
set to NULL.
*****************************************************************************/
void XglNodeDeclareArray::set(XglNode *initialize)
{
	this->initialize = initialize;
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeDeclareArray::execute(XglContext *context)
{
	XglSymbolTable *symbolTable = context->getSymbolTable();

	XglSymbolTableRecDesType designation = XglSymbolTableRecDesType::ARRAY;

	XglValue *value = NULL;

	if (initialize != NULL) {
		value = initialize->execute(context);
	}

	symbolTable->add(designation, type, variable, calcArraySize(context), value);

	return(NULL);
}

int XglNodeDeclareArray::calcArraySize(XglContext *context)
{
	int size = 1;

	for (XglNode *arrayElement : getAttributes()) {
		size *= arrayElement->execute(context)->getInteger();
	}

	return(size);
}
