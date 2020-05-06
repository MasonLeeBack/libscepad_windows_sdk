/*

libScePad

Copyright by Sony Computer Entertainment
Header by github/MasonLeeBack

*/

#ifndef _LIBSCEPAD_H_
#define _LIBSCEPAD_H_

#include <stdint.h>

#if !defined(_WIN32) || !defined(_WIN64)
#error This library is only compatible with Windows 64-bit systems.
#endif

// Error codes
#define SCE_OK 0

// Button mask
#define DS4_BM_CROSS    0x00004000
#define DS4_BM_CIRCLE   0x00002000
#define DS4_BM_TRIANGLE 0x00001000
#define DS4_BM_SQUARE   0x00008000

#define DS4_BM_L1       0x00000400
#define DS4_BM_L2       0x00000100
#define DS4_BM_R1       0x00000800
#define DS4_BM_R2       0x00000200

#define DS4_BM_L3       0x00000002
#define DS4_BM_R3       0x00000004

#define DS4_BM_N_DPAD   0x00000010
#define DS4_BM_S_DPAD   0x00000040
#define DS4_BM_E_DPAD   0x00000020
#define DS4_BM_W_DPAD   0x00000080

#define DS4_BM_OPTIONS  0x00000008

#define DS4_BM_TOUCH    0x00100000

// Call sceSetParticularMode(true) to use these
#define DS4_BM_SHARE    0x00000001
#define DS4_BM_PSBTN    0x00010000

typedef struct {
    uint8_t X;
    uint8_t Y;
} s_SceStickData;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} s_SceLightBar;

// TODO: Things to be figured out later
//      Offsets for the gyroscope, touchpad, etc.
// 120 bytes
typedef struct {
    uint32_t bitmask_buttons;
    s_SceStickData LeftStick;
    s_SceStickData RightStick;
    uint8_t L2_Analog;
    uint8_t R2_Analog;
    char oth[110];
} s_ScePadData;

#ifdef __cplusplus
extern "C" {
#endif

int scePadClose(int handle);
int scePadInit(void);
int scePadOpen(int userID, int, int, void*);
int scePadRead(int handle, void* data, int count);
int scePadReadState(int handle, void* data);
int scePadSetParticularMode(bool);
int scePadSetLightBar(int handle, void* lightdata);
int scePadResetLightBar(int handle);

#ifdef __cplusplus
}
#endif

#endif // _LIBSCEPAD_H_
