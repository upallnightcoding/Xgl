#include "pch.h"
#include "XglSymbolTableData.h"


XglSymbolTableData::XglSymbolTableData(XglValueType type, int size, XglValue *initialize)
{
	this->svalue = NULL;
	this->lvalue = NULL;
	this->dvalue = NULL;
	this->bvalue = NULL;

	this->value = new XglValue();

	this->type = type;

	allocateData(type, size);

	if (initialize != NULL) {
		assign(0, initialize);
	}
}

XglSymbolTableData::~XglSymbolTableData()
{
	if (svalue != NULL) {
		delete svalue;
	}

	if (lvalue != NULL) {
		delete lvalue;
	}

	if (dvalue != NULL) {
		delete dvalue;
	}

	if (bvalue != NULL) {
		delete bvalue;
	}

	delete value;
}

/*****************************************************************************
assign() -
*****************************************************************************/
void XglSymbolTableData::assign(XglValue *value)
{
	assign(0, value);
}

/*void XglSymbolTableData::assign(XglNode *variable, XglValue *value)
{

}*/

/*****************************************************************************
assign() -
*****************************************************************************/
void XglSymbolTableData::assign(int index, XglValue *value)
{
	switch (type) {
	case XglValueType::INTEGER:
		lvalue[index] = value->getInteger();
		break;
	case XglValueType::REAL:
		dvalue[index] = value->getReal();
		break;
	case XglValueType::STRING:
		svalue[index] = value->getString();
		break;
	case XglValueType::BOOLEAN:
		bvalue[index] = value->getBool();
		break;
	}
}

/*****************************************************************************
getValue() -
*****************************************************************************/
XglValue *XglSymbolTableData::getValue(int index)
{
	switch (type) {
	case XglValueType::INTEGER:
		value->set(lvalue[index]);
		break;
	case XglValueType::REAL:
		value->set(dvalue[index]);
		break;
	case XglValueType::STRING:
		value->set(svalue[index]);
		break;
	case XglValueType::BOOLEAN:
		value->set(bvalue[index]);
		break;
	}

	return(value);
}

/*****************************************************************************
allocateData() -
*****************************************************************************/
void XglSymbolTableData::allocateData(XglValueType type, int size)
{
	switch (type) {
	case XglValueType::INTEGER:
		lvalue = new long[size];
		break;
	case XglValueType::REAL:
		dvalue = new double[size];
		break;
	case XglValueType::STRING:
		svalue = new string[size];
		break;
	case XglValueType::BOOLEAN:
		bvalue = new bool[size];
		break;
	}
}
