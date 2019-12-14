#include "pch.h"
#include "XglSymbolTableRec.h"


XglSymbolTableRec::XglSymbolTableRec(XglToken *type, XglToken *variable, XglNode *expression)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->expression = expression;
	this->value = NULL;
}

XglSymbolTableRec::XglSymbolTableRec(XglToken *type, XglToken *variable, int size, XglNode *expression)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = XglSymbolTableRecDesType::SCALER;
	this->expression = expression;
	this->size = size;
	this->data = new XglSymbolTableData(this->type, size);
	this->value = NULL;
}

XglSymbolTableRec::XglSymbolTableRec(string variable, bool value)
{
	this->variable = variable;
	this->type = XglValueType::BOOLEAN;
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->expression = NULL;
	this->value = new XglValue(value);
}

XglSymbolTableRec::XglSymbolTableRec(string variable, double value)
{
	this->variable = variable;
	this->type = XglValueType::REAL;
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->expression = NULL;
	this->value = new XglValue(value);
}


XglSymbolTableRec::~XglSymbolTableRec()
{
}

/*****************************************************************************
getVariableName() -
*****************************************************************************/
string XglSymbolTableRec::getVariableName()
{
	return(variable);
}

/*****************************************************************************
getValue() - 
*****************************************************************************/
XglValue *XglSymbolTableRec::getValue(XglContext &context)
{
	XglValue *returnValue = NULL;

	switch (designation) {
	case XglSymbolTableRecDesType::CONSTANT:
		if (value == NULL) {
			value = expression->execute(context);
		}
		returnValue = value;
		break;
	case XglSymbolTableRecDesType::SCALER:
		if (expression != NULL) {
			value = expression->execute(context);
			data->set(0, value);
		}

		returnValue = data->getValue();
		break;
	}
	
	return(returnValue);
}

/*****************************************************************************
isConstant() -  
*****************************************************************************/
bool XglSymbolTableRec::isConstant()
{
	return(designation == XglSymbolTableRecDesType::CONSTANT);
}

