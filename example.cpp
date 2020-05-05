/*

example app

*/

#include <Windows.h>
#include <stdio.h>
#include <libscepad.h>

int main(int argc, char* argv[])
{
	int PadHandle = 0;

	// Initialize ScePad
	if (scePadInit() != SCE_OK)
		return -1;

	PadHandle = scePadOpen(1, NULL, NULL, NULL);

	if (PadHandle <= 0)
		return -2;

	scePadSetParticularMode(true);

	while (1) {
		s_ScePadData data;
		system("cls");
		if (scePadReadState(PadHandle, &data) == SCE_OK) {
			printf("%08X\n", data.bitmask_buttons);

			printf("%02X ", data.ls_x);
			printf("%02X \n", data.ls_y);

			printf("%02X ", data.rs_x);
			printf("%02X ", data.rs_y);

			if (data.bitmask_buttons & DS4_BM_OPTIONS)
				break;
		}

		Sleep(100);
	}

	scePadClose(PadHandle);

	return 0;
}