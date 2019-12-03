#include "pch.h"
#include "XglCommandProgram.h"
#include "XglNodeExecute.h"
#include "XglNodeProgram.h"

XglCommandProgram::XglCommandProgram() 
	: XglCommand("PROGRAM")
{
}


XglCommandProgram::~XglCommandProgram()
{
}

XglNode *XglCommandProgram::execute(XglInterpreterAbstract *interpreter)
{
	interpreter->getToken();

	XglNode *code = new XglNodeExecute();

	XglNode *statement = interpreter->parseStatement();

	while (!statement->isEnd()) {
		code->add(statement);

		statement = interpreter->parseStatement();
	}

	XglNode *command = new XglNodeProgram();

	command->add(code);

	return(command);
}
