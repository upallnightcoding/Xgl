// XglTestProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "XglProgram.h"
#include "XglInterpreter.h"
#include "XglContext.h"

int main()
{
	XglContext context(new XglSymbolTable());
	XglProgram program;
	XglInterpreter interpreter(program);
	XglNode *node = NULL;

	node = interpreter.parseStatement();

	node->execute(context);
}
