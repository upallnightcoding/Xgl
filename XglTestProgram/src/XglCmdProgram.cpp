#include "pch.h"
#include "XglCmdProgram.h"
#include "XglNodeCodeBlock.h"
#include "XglNodeProgram.h"

XglCmdProgram::XglCmdProgram() 
	: XglCmd("PROGRAM")
{
}


XglCmdProgram::~XglCmdProgram()
{
}


/*****************************************************************************
execute() -
*****************************************************************************/
XglNode *XglCmdProgram::execute(XglInterpreter *interpreter)
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
