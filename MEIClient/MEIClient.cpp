// MEIClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FWInfoWin32.h"

int main()
{
	intel_dal::FWInfoWin32 mei;

	if (mei.Connect()) {
		std::cout << "Success connection ME interface" << std::endl;

		::VERSION fw_ver;
		::ZeroMemory(&fw_ver, sizeof(fw_ver));
		if (mei.GetFwVersion(&fw_ver))
			std::cout << "ME Firmware:" << fw_ver.Major << "." <<
				fw_ver.Minor << "." << fw_ver.Hotfix << "#" <<
				fw_ver.Build << std::endl;

		std::cout << "will send ME Reset & Halt command" << std::endl;
		::GEN_SET_MFG_MRST_AND_HALT_ACK gen_rst;
		::ZeroMemory(&gen_rst, sizeof(gen_rst));
		gen_rst.Header.Fields.GroupId = MKHI_GEN_GROUP_ID;
		gen_rst.Header.Fields.Command = GEN_SET_MFG_MRST_AND_HALT_CMD;
		gen_rst.Header.Fields.IsResponse = 0;
		if (mei.HeciWrite(mei.GetHandle(), &gen_rst, sizeof(gen_rst), INFINITE))
			std::cout << "complete send Reset & Halt command" << std::endl;
		else
		{
			std::cout << "Failed: send Reset & Halt command" << std::endl;
			mei.Disconnect();
			return -1;
		}
		mei.Disconnect();
	}
    return 0;
}

