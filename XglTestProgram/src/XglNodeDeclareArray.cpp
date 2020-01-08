#include "pch.h"
#include "XglNodeDeclareArray.h"


XglNodeDeclareArray::XglNodeDeclareArray(XglToken *type, XglToken *variable, XglNode *arraySize)
	: XglNode(XglNodeType::NODE_DECLARE_ARRAY)
{
	this->type = type;
	this->variable = variable;
	this->arraySize = arraySize;
}

XglNodeDeclareArray::~XglNodeDeclareArray()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeDeclareArray::execute(XglContext *context)
{
	XglSymbolTable *symbolTable = context->getSymbolTable();

	int size = arraySize->execute(context)->getInteger();

	symbolTable->add(type, variable, size, NULL);

	return(NULL);
}
