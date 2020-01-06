#pragma once

#include "Xgl.h"

#include "XglValue.h"
#include "XglContext.h"

enum class XglNodeType
{
	NODE_UNKNOWN,
	NODE_PROGRAM,
	NODE_PRINT,
	NODE_ASSIGN,
	NODE_FOR,
	NODE_WHILE,
	NODE_EXEC,
	NODE_IF,
	NODE_ELSEIF,
	NODE_END,
	NODE_ELSE,
	NODE_FUNCTION,

	NODE_DECLARE,
	NODE_DECLARE_VARIABLE,

	NODE_CONST,
	NODE_DECLARE_CONST,

	NODE_VARIABLE,

	NODE_EQ,
	NODE_NE,
	NODE_LT,
	NODE_GT,
	NODE_GE,
	NODE_LE,

	NODE_NEG,
	NODE_NOT,

	NODE_SYSTEM_FUNCTION,

	NODE_TRIPLET,

	NODE_ADD,
	NODE_SUB,
	NODE_DIVIDE,
	NODE_MULTI,
	NODE_VALUE
};

class XglNode
{
public:
	XglNode(XglNodeType type);
	virtual ~XglNode();

public:
	virtual XglValue *execute(XglContext *context) = 0;

	XglValue *evaluate(XglContext *context);
	XglValue *evaluate(int index, XglContext *context);

	void add(XglNode *node);

	vector<XglNode*> getAttributes();

	bool isEnd();
	bool isElse();
	bool isElseIf();

private:
	vector<XglNode*> children;
	XglNodeType type;
};

