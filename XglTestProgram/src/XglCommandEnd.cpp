#include "pch.h"
#include "XglCommandEnd.h"
#include "XglNodeEnd.h"


XglCommandEnd::XglCommandEnd() : XglCommand("END")
{
}


XglCommandEnd::~XglCommandEnd()
{
}

XglNode *XglCommandEnd::execute(XglInterpreterAbstract *interpreter)
{
	interpreter->getToken();

	return(new XglNodeEnd());
}
