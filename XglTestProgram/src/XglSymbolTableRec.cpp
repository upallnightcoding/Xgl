#include "pch.h"
#include "XglSymbolTableRec.h"
#include "XglNodeValue.h"

XglSymbolTableRec::XglSymbolTableRec(XglSymbolTableRecDesType designation, XglToken *type, XglToken *variable, XglValue *initialize)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = designation;
	this->data = new XglSymbolTableData(this->type, initialize);
}

XglSymbolTableRec::XglSymbolTableRec(XglToken *type, XglToken *variable, vector<int> &dimensions, XglValue *initialize)
{
	this->variable = variable->getString();
	this->type = type->getTypeFromKeyword();
	this->designation = XglSymbolTableRecDesType::ARRAY;
	this->data = new XglSymbolTableData(this->type, dimensions, initialize);
}

XglSymbolTableRec::XglSymbolTableRec(XglValueType type, string variable, XglValue *initialize)
{
	this->variable = variable;
	this->type = type;
	this->designation = XglSymbolTableRecDesType::CONSTANT;
	this->data = new XglSymbolTableData(this->type, initialize);
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
XglValue *XglSymbolTableRec::access(vector<int> elements)
{
	XglValue *value = NULL;

	/*switch (designation) {
	case XglSymbolTableRecDesType::CONSTANT:
	case XglSymbolTableRecDesType::SCALER:
		value = data->getValue();
		break;
	case XglSymbolTableRecDesType::ARRAY:
		value = data->getValue(index);
		break;
	}*/
	
	return(data->access(elements));
}

/*****************************************************************************
assign() - 
*****************************************************************************/
void XglSymbolTableRec::assign(vector<int> elements, XglValue *value)
{
	data->assign(elements, value);
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

