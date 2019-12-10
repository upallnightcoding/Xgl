#include "pch.h"
#include "XglSymbolTableRec.h"


XglSymbolTableRec::XglSymbolTableRec(XglToken *type, XglToken *variable, XglNode *expression)
{
	this->name = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->expression = expression;
	this->value = NULL;
}


XglSymbolTableRec::~XglSymbolTableRec()
{
}

/*****************************************************************************
getValue() - 
*****************************************************************************/
XglValue *XglSymbolTableRec::getValue(XglContext &context)
{
	value = expression->execute(context);

	return(value);
}

/*****************************************************************************
isConstant() -  
*****************************************************************************/
bool XglSymbolTableRec::isConstant()
{
	return(designation == XglSymbolTableRecDesType::CONSTANT);
}

