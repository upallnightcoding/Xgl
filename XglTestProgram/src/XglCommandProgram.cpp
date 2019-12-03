#include "pch.h"
#include "XglCommandProgram.h"
#include "XglNodeCodeBlock.h"
#include "XglNodeProgram.h"

XglCommandProgram::XglCommandProgram() 
	: XglCommand("PROGRAM")
{
}


XglCommandProgram::~XglCommandProgram()
{
}


/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCommandProgram::execute(XglInterpreterAbstract *interpreter)
{
	interpreter->getToken();

	XglNode *code = new XglNodeCodeBlock();

	XglNode *statement = interpreter->parseStatement();

	while (!statement->isEnd()) {
		code->add(statement);

		statement = interpreter->parseStatement();
	}

	XglNode *command = new XglNodeProgram();

	command->add(code);

	return(command);
}
