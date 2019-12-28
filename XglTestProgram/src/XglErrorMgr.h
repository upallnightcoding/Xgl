#pragma once

#include "Xgl.h"

enum class XglErrorMessageType
{
	EOS_EXPECTED,
	UNKNOWN
};

class XglErrorMgr
{
public:
	XglErrorMgr();
	virtual ~XglErrorMgr();

public:
	string getErrorMessage(XglErrorMessageType type);

private:
	int nErrors;
};

