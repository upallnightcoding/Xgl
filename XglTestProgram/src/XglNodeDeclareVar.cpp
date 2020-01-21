#include "pch.h"
#include "XglNodeDeclareVar.h"


XglNodeDeclareVar::XglNodeDeclareVar(XglToken *type, XglToken *variable, XglNode *initialize)
	: XglNode(XglNodeType::NODE_DECLARE_VARIABLE)
{
	this->type = type;
	this->variable = variable;
	this->initialize = initialize;
}

XglNodeDeclareVar::XglNodeDeclareVar(XglToken *type, XglToken *variable) 
	: XglNode(XglNodeType::NODE_DECLARE_VARIABLE)
{
	this->type = type;
	this->variable = variable;
	this->initialize = NULL;
}

XglNodeDeclareVar::~XglNodeDeclareVar()
{
}

/*****************************************************************************
set() - Sets the value that will be used to initialize the variable upon
declaration.  If there is no initialization, the initialize value should be
set to NULL.
*****************************************************************************/
void XglNodeDeclareVar::set(XglNode *initialize)
{
	this->initialize = initialize;
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeDeclareVar::execute(XglContext *context)
{
	XglSymbolTable *symbolTable = context->getSymbolTable();

	XglValue *value = (initialize != NULL) ? initialize->execute(context) : NULL;

	symbolTable->declareScalar(type, variable, value);

	return(NULL);
}
