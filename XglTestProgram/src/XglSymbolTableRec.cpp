#include "pch.h"
#include "XglSymbolTableRec.h"


XglSymbolTableRec::XglSymbolTableRec(XglToken *type, XglToken *variable, XglNode *expression)
{
	this->name = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->expression = expression;
}


XglSymbolTableRec::~XglSymbolTableRec()
{
}

