#include "pch.h"
#include "XglNodeFor.h"


XglNodeFor::XglNodeFor(XglToken *type, XglToken *variable, XglNode *init, XglNode *fin, XglNode *step) :
	XglNode(XglNodeType::NODE_FOR)
{
	this->type = type;
	this->variable = variable;
	this->init = init;
	this->fin = fin;
	this->step = step;

	this->firstLoop = true;
}


XglNodeFor::~XglNodeFor()
{
}

XglValue *XglNodeFor::execute(XglContext &context)
{
	if (firstLoop) {
		firstLoop = false;

		XglSymbolTable *symbolTable = context.getSymbolTable();

		symbolTable->add(type, variable, 1, init);
	}

	return(NULL);
}
