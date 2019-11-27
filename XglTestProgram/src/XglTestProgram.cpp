// XglTestProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "XglProgram.h"

int main()
{
	XglProgram program;
	XglToken *token = NULL;

	do {
		token = program.getToken();
	} while (token != NULL);
}
