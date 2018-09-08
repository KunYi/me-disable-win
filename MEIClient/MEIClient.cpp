// MEIClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MkhiMsgs.h"
#pragma pack(1)


int main()
{
	GEN_SET_MFG_MRST_AND_HALT_ACK gen_rst;
	gen_rst.Header.Fields.GroupId = MKHI_GEN_GROUP_ID;
	gen_rst.Header.Fields.Command = GEN_SET_MFG_MRST_AND_HALT_CMD;

    return 0;
}

