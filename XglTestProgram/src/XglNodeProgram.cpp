#include "pch.h"
#include "XglNodeProgram.h"


XglNodeProgram::XglNodeProgram() : XglNode(XglNodeType::NODE_PROGRAM)
{
}


XglNodeProgram::~XglNodeProgram()
{
}

XglValue *XglNodeProgram::execute()
{
	evaluate(0);

	return(NULL);
}
