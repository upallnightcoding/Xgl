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

XglValue *XglNodeConstVar::execute(XglContext &context)
{
	XglSymbolTable *symbolTable = context.getSymbolTable();

	symbolTable->add(type, variable, expression);

	return(NULL);
}
