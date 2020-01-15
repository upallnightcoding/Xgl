#include "pch.h"
#include "XglNodeConstVar.h"


 XglNodeConstVar::XglNodeConstVar(XglToken *type, XglToken *variable, XglNode *expression) 
	 : XglNode(XglNodeType::NODE_DECLARE_CONST)
{
	 this->type = type;
	 this->variable = variable;
	 this->expression = expression;
}


XglNodeConstVar::~XglNodeConstVar()
{
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeConstVar::execute(XglContext *context)
{
	XglSymbolTable *symbolTable = context->getSymbolTable();

	XglValue *initialize = expression->execute(context);

	symbolTable->add(type, variable, initialize);

	return(NULL);
}
