#include "pch.h"
#include "XglCmdEnd.h"
#include "XglNodeEnd.h"


XglCmdEnd::XglCmdEnd() : XglCmd("END")
{
}


XglCmdEnd::~XglCmdEnd()
{
}

XglNode *XglCmdEnd::execute(XglInterpreterAbstract *interpreter)
{
	interpreter->getToken();

	return(new XglNodeEnd());
}
