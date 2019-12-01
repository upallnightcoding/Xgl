#include "pch.h"
#include "XglCommandPrint.h"
#include "XglNodePrint.h"


XglCommandPrint::XglCommandPrint()
{
}


XglCommandPrint::~XglCommandPrint()
{
}

XglNode *XglCommandPrint::execute(XglInterpreter &interpreter)
{
	XglNode *command = new XglNodePrint();

	return(command);
}
