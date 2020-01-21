#include "pch.h"
#include "XglNodeAssign.h"

XglNodeAssign::XglNodeAssign(XglNodeAssignVar *variable, XglNode *value) 
	: XglNode(XglNodeType::NODE_ASSIGN)
{
	this->variable = variable;
	this->value = value;
}

XglNodeAssign::XglNodeAssign(XglToken *variable, XglNode *expression) 
	: XglNode(XglNodeType::NODE_ASSIGN)
{
	this->variable = new XglNodeAssignVar(variable->getString());
	this->value = expression;
}

XglNodeAssign::~XglNodeAssign()
{
	delete variable;
	delete value;
}

/*****************************************************************************
execute() -
*****************************************************************************/
XglValue *XglNodeAssign::execute(XglContext *context)
{
	string variableName = variable->getVariableName();

	XglValue *calcValue = value->execute(context);

	vector<int> elements;

	for (XglNode *element : variable->getAttributes()) {
		int elementIndex = element->execute(context)->getInteger();
		elements.push_back(elementIndex);
	}

	context->getSymbolTable()->assign(variableName, elements, calcValue);

	return(NULL);
}

