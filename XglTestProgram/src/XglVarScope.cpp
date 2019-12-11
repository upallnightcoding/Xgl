#include "pch.h"
#include "XglVarScope.h"


XglVarScope::XglVarScope()
{
}


XglVarScope::~XglVarScope()
{
}

void XglVarScope::add(XglSymbolTableRec *record)
{
	scope[record->getVariableName()] = record;
}

XglSymbolTableRec *XglVarScope::get(string name)
{
	return(scope[name]);
}
