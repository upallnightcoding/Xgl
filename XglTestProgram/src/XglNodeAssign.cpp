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
	XglValue *constant = value->execute(context);

	string variableName = variable->getVariableName();

	XglSymbolTableRec *record = context->getSymbolTable()->find(variableName);

	if (record != NULL) {
		if (record->isConstant() || record->isScaler()) {
			record->getData()->assign(0, constant);
		} else if (record->isArray()) {
			int index = variable->evaluate(0, context)->getInteger();
			record->getData()->assign(index, constant);
		}

	}

	return(NULL);
}
