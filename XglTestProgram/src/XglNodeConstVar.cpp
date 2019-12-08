#include "pch.h"
#include "XglNodeConstVar.h"


 XglNodeConstVar::XglNodeConstVar(XglToken *type, XglToken *variable, XglNode *expression) 
	 : XglNode(XglNodeType::NODE_CONST_VARIABLE)
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
	return(NULL);
}
