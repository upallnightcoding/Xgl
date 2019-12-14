#include "pch.h"
#include "XglSymbolTableData.h"


XglSymbolTableData::XglSymbolTableData(XglValueType type, int size)
{
	this->svalue = NULL;
	this->lvalue = NULL;
	this->dvalue = NULL;
	this->bvalue = NULL;

	this->value = new XglValue();

	this->type = type;

	allocateData(type, size);
}

XglSymbolTableData::~XglSymbolTableData()
{
}

void XglSymbolTableData::set(int index, XglValue *value)
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

XglValue *XglSymbolTableData::getValue()
{
	switch (type) {
	case XglValueType::INTEGER:
		value->set(lvalue[0]);
		break;
	case XglValueType::REAL:
		value->set(dvalue[0]);
		break;
	case XglValueType::STRING:
		value->set(svalue[0]);
		break;
	case XglValueType::BOOLEAN:
		value->set(bvalue[0]);
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
