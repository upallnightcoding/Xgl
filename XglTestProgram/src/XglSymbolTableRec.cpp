#include "pch.h"
#include "XglSymbolTableRec.h"
#include "XglNodeValue.h"

XglSymbolTableRec::XglSymbolTableRec(XglToken *type, XglToken *variable, XglValue *initialize)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->size = 1;
	this->data = new XglSymbolTableData(this->type, size, initialize);
}

XglSymbolTableRec::XglSymbolTableRec(XglSymbolTableRecDesType designation, XglToken *type, XglToken *variable, int size, XglValue *initialize)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = designation;
	this->size = size;
	this->data = new XglSymbolTableData(this->type, size, initialize);
}

XglSymbolTableRec::XglSymbolTableRec(XglValueType type, string variable, XglValue *initialize)
{
	this->variable = variable;
	this->type = type;
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->size = 1;
	this->data = new XglSymbolTableData(this->type, size, initialize);
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
access() -
*****************************************************************************/
XglValue *XglSymbolTableRec::access(int index)
{
	XglValue *returnValue = NULL;

	switch (designation) {
	case XglSymbolTableRecDesType::CONSTANT:
		returnValue = data->getValue(0);
		break;
	case XglSymbolTableRecDesType::SCALER:
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

