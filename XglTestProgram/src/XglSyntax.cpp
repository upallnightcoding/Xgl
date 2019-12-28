#include "pch.h"
#include "XglSyntax.h"


XglSyntax::XglSyntax(XglInterpreter *interpreter)
{
	this->interpreter = interpreter;
	this->errorMrg = new XglErrorMgr();
}

XglSyntax::~XglSyntax()
{
	delete interpreter;
	delete errorMrg;
}

XglInterpreter *XglSyntax::getInterpreter()
{
	return(interpreter);
}

void XglSyntax::error(XglErrorMessageType type)
{
	string message = errorMrg->getErrorMessage(type);
}
