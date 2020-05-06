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
            // Mask for buttons
            printf("Buttons: %08X\n", data.bitmask_buttons);

            // Sticks
            printf("Left stick: %02X %02X\n", data.LeftStick.X, data.LeftStick.Y);
            printf("Right stick: %02X %02X\n", data.RightStick.X, data.RightStick.Y);

            printf("L2: %02X R2 %02X\n", data.L2_Analog, data.R2_Analog);

            if (data.bitmask_buttons & DS4_BM_OPTIONS)
                break;
        }

        Sleep(200);
    }

    scePadClose(PadHandle);

    return 0;
}
