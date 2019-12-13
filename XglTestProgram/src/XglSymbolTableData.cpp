#include "pch.h"
#include "XglSymbolTableData.h"


XglSymbolTableData::XglSymbolTableData()
{
	svalue = NULL;
	lvalue = NULL;
	dvalue = NULL;
	bvalue = NULL;
}


XglSymbolTableData::~XglSymbolTableData()
{
}

void XglSymbolTableData::allocateData(XglValueType type, int size)
{

}
