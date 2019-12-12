#include "pch.h"
#include "XglCommandDeclare.h"


XglCommandDeclare::XglCommandDeclare() : XglCommand("DECLARE")
{
}


XglCommandDeclare::~XglCommandDeclare()
{
}

XglNode *XglCommandDeclare::execute(XglInterpreterAbstract *interpreter)
{
	return(NULL);
}
