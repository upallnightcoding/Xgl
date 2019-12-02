#include "pch.h"
#include "XglCommand.h"


XglCommand::XglCommand(string name)
{
	this->name = name;
}

XglCommand::~XglCommand()
{
}

string XglCommand::getName()
{
	return(name);
}
