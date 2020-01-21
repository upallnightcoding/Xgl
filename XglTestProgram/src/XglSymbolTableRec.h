#pragma once

#include "Xgl.h"
#include "XglValue.h"

enum class XglSymbolTableRecDesType {
	UNKNOWN,
	SCALER,
	ARRAY,
	CONSTANT
};

class XglNode;
class XglContext;
class XglSymbolTableData;

/*****************************************************************************
XglSymbolTableRec -
*****************************************************************************/
class XglSymbolTableRec
{
public:
	// Xgl Internal Constants
	XglSymbolTableRec(
		XglValueType type, 
		string variable, 
		XglValue *initialize
	);

	// Symbol Table Constants
	XglSymbolTableRec(
		XglSymbolTableRecDesType designation, 
		XglToken *type, 
		XglToken *variable, 
		XglValue *initialize
	);

	// Scalar & Array Variables
	XglSymbolTableRec(
		XglToken *type, 
		XglToken *variable, 
		vector<int> &dimensions, 
		XglValue *initialize
	);
	
	virtual ~XglSymbolTableRec();

public:
	XglValue *access(vector<int> elements);
	void assign(vector<int> elements, XglValue *value);

	string getVariableName();
	XglSymbolTableData *getData();
	

	bool isConstant();
	bool isScaler();
	bool isArray();

private:
	// Variable Name
	string variable;

	// Tyep of variable, integer, real, boolean, string ...
	XglValueType type;

	// Designation of the vairable, scalar, array, function, procedure ...
	XglSymbolTableRecDesType designation;

	// Value help by scalars and arrays
	XglSymbolTableData *data;
};

#include "XglNode.h"
#include "XglContext.h"
#include "XglSymbolTableData.h"