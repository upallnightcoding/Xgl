#include "pch.h"
#include "XglSymbolTableRec.h"
#include "XglNodeValue.h"

XglSymbolTableRec::XglSymbolTableRec(XglToken *type, XglToken *variable, XglNode *expression)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->expression = expression;
	this->size = 1;
	this->data = NULL;
}

XglSymbolTableRec::XglSymbolTableRec(XglToken *type, XglToken *variable, int size, XglNode *expression)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = XglSymbolTableRecDesType::SCALER;
	this->expression = expression;
	this->hasInitializeExpression = (expression != NULL);
	this->size = size;
	this->data = new XglSymbolTableData(this->type, size);
}

XglSymbolTableRec::XglSymbolTableRec(string variable, bool value)
{
	this->variable = variable;
	this->type = XglValueType::BOOLEAN;
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->expression = new XglNodeValue(new XglValue(value));
	this->size = 1;
	this->data = NULL;
}

XglSymbolTableRec::XglSymbolTableRec(string variable, double value)
{
	this->variable = variable;
	this->type = XglValueType::REAL;
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->expression = new XglNodeValue(new XglValue(value));
	this->size = 1;
	this->data = NULL;
}


XglSymbolTableRec::~XglSymbolTableRec()
{
}

/*****************************************************************************
getData() -
*****************************************************************************/
XglSymbolTableData *XglSymbolTableRec::getData()
{
	return(data);
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
XglValue *XglSymbolTableRec::getValue(XglContext *context)
{
	XglValue *returnValue = NULL;

	switch (designation) {
	case XglSymbolTableRecDesType::CONSTANT:
		if (data == NULL) {
			data = new XglSymbolTableData(type, size);
			data->assign(0, expression->execute(context));
		}

		returnValue = data->getValue(0);

		break;
	case XglSymbolTableRecDesType::SCALER:
		if (hasInitializeExpression) {
			XglValue *value = expression->execute(context);
			data->assign(0, value);
			hasInitializeExpression = false;
		}

		returnValue = data->getValue(0);

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

