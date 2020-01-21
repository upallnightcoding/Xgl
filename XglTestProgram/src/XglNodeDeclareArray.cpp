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

	XglValue *value = (initialize != NULL) ? initialize->execute(context) : NULL;

	vector<int> arraryElements = declareArraySize(context);

	symbolTable->declareArray(type, variable, arraryElements, value);

	return(NULL);
}

/*****************************************************************************
calcArraySize() -
*****************************************************************************/
vector<int> XglNodeDeclareArray::declareArraySize(XglContext *context)
{
	vector<int> elements;

	for (XglNode *arrayElement : getAttributes()) {
		elements.push_back(arrayElement->execute(context)->getInteger());
	}

	return(elements);
}
