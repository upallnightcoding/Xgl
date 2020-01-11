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

XglSymbolTableRec::XglSymbolTableRec(XglSymbolTableRecDesType designation, XglToken *type, XglToken *variable, int size, XglNode *expression)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = designation;
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
XglValue *XglSymbolTableRec::access(int index, XglContext *context)
{
	XglValue *returnValue = NULL;

	switch (designation) {
	case XglSymbolTableRecDesType::CONSTANT:
		if (data == NULL) {
			data = new XglSymbolTableData(type, size);
			data->assign(index, expression->execute(context));
		}

		returnValue = data->getValue(0);

		break;
	case XglSymbolTableRecDesType::SCALER:
		if (hasInitializeExpression) {
			hasInitializeExpression = false;
			XglValue *value = expression->execute(context);
			data->assign(index, value);
		}

		returnValue = data->getValue(index);

		break;
	case XglSymbolTableRecDesType::ARRAY:
		returnValue = data->getValue(index);
		break;
	}
	
	return(returnValue);
}

/*****************************************************************************
isConstant() - Return true if the symbol table record represents a constant.
*****************************************************************************/
bool XglSymbolTableRec::isConstant()
{
	return(designation == XglSymbolTableRecDesType::CONSTANT);
}

/*****************************************************************************
isScaler() - Return true if the symbol table record represents a scaler.
*****************************************************************************/
bool XglSymbolTableRec::isScaler() 
{
	return(designation == XglSymbolTableRecDesType::SCALER);
}

/*****************************************************************************
isArray() - Return true if the symbol table record represents a array.
*****************************************************************************/
bool XglSymbolTableRec::isArray()
{
	return(designation == XglSymbolTableRecDesType::ARRAY);
}

