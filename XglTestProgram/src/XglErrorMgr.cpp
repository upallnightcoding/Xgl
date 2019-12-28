#include "pch.h"
#include "XglErrorMgr.h"


XglErrorMgr::XglErrorMgr()
{
	this->nErrors = 0;
}


XglErrorMgr::~XglErrorMgr()
{
}

string XglErrorMgr::getErrorMessage(XglErrorMessageType type)
{
	string msg = "";

	switch (type) {
	case XglErrorMessageType::EOS_EXPECTED:
		msg = "End of statement was expected but not found.";
	break;
	}

	nErrors++;

	return(msg);
}
