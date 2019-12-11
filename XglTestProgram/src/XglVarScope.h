#pragma once

#include "Xgl.h"
#include "XglSymbolTableRec.h"

class XglVarScope
{
public:
	XglVarScope();
	virtual ~XglVarScope();

public:
	void add(XglSymbolTableRec *record);
	XglSymbolTableRec *get(string name);

private:
	map<string, XglSymbolTableRec*> scope;
};

