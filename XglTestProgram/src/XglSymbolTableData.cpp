#include "pch.h"
#include "XglSymbolTableData.h"


XglSymbolTableData::XglSymbolTableData(XglValueType type, XglValue *initialize)
{
	init(type, 1, initialize);
}

XglSymbolTableData::XglSymbolTableData(XglValueType type, vector<int> &dimensions, XglValue *initialize)
{
	int size = 1;

	for (int dimension : dimensions) {
		size *= dimension;
	}

	init(type, size, initialize);
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
init() -
*****************************************************************************/
void XglSymbolTableData::init(XglValueType type, int size, XglValue *initialize)
{
	this->svalue = NULL;
	this->lvalue = NULL;
	this->dvalue = NULL;
	this->bvalue = NULL;

	this->value = new XglValue();

	this->type = type;

	this->width = 0;

	allocateData(type, size);

	assign(0, initialize);
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

void XglSymbolTableData::assign(int col, int row, XglValue *value)
{
	int index = row * width + col;

	assign(index, value);
}

/*****************************************************************************
assign() -
*****************************************************************************/
void XglSymbolTableData::assign(vector<int> elements, XglValue *value)
{
	int index = calcArrayIndex(elements);

	if (index != -1) {
		assign(index, value);
	}
}

int XglSymbolTableData::calcArrayIndex(vector<int> elements)
{
	int index = -1;

	switch (elements.size()) {
	case 0:
		index = 0;
		break;
	case 1:
		index = elements.at(0);
		break;
	case 2: {
		int col = elements.at(0);
		int row = elements.at(1);
		index = row * width + col;
		break;
		}
	}

	return(index);
}

/*****************************************************************************
assign() -
*****************************************************************************/
void XglSymbolTableData::assign(int index, XglValue *value)
{
	if (value != NULL) {
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
}

/*****************************************************************************
access() -
*****************************************************************************/
XglValue *XglSymbolTableData::access(vector<int> elements)
{
	XglValue *value = NULL;

	int index = calcArrayIndex(elements);

	if (index != -1) {
		value = getValue(index);
	}

	return(value);
}

/*****************************************************************************
getValue() -
*****************************************************************************/
XglValue *XglSymbolTableData::getValue()
{
	return(getValue(0));
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
