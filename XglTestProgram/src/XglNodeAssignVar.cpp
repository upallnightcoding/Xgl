#include "pch.h"
#include "XglNodeAssignVar.h"


XglNodeAssignVar::XglNodeAssignVar(string variableName) 
	: XglNode(XglNodeType::NODE_ASSIGN_VAR)
{
	this->variableName = variableName;
}


XglNodeAssignVar::~XglNodeAssignVar()
{
}

string XglNodeAssignVar::getVariableName()
{
	return(variableName);
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeAssignVar::execute(XglContext *context)
{
	return(NULL);
}
