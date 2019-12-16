#include "pch.h"
#include "XglCmd.h"


XglCmd::XglCmd(string name)
{
	this->name = name;
}

XglCmd::~XglCmd()
{
}

/*****************************************************************************
getName() -
*****************************************************************************/
string XglCmd::getName()
{
	return(name);
}
