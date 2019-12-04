#include "pch.h"
#include "XglNodeProgram.h"


XglNodeProgram::XglNodeProgram() : XglNode(XglNodeType::NODE_PROGRAM)
{
}


XglNodeProgram::~XglNodeProgram()
{
}

XglValue *XglNodeProgram::execute(XglContext &context)
{
	evaluate(0, context);

	return(NULL);
}
