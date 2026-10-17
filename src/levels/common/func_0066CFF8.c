#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} S_66CFF8_8;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} S_66CFF8_16;

typedef struct {
    s32 w[8];
} S_66CFF8_32;

typedef struct {
    u8 b;
    u8 pad[3];
} S_66CFF8_Slot;

typedef struct {
    u8 pad0[0x88];
    S_66CFF8_Slot slots[8];
} S_66CFF8_Src;

typedef struct {
    s32 w0;
    s32 w4;
    u8 b8;
    u8 pad9[3];
    u8 bC;
    u8 padD[0x18 - 0xD];
    S_66CFF8_32 s18;
    S_66CFF8_8 s38;
    u8 pad40[0x48 - 0x40];
    S_66CFF8_8 s48;
    S_66CFF8_8 s50;
    u8 pad58[0x198 - 0x58];
    S_66CFF8_16 s198;
    u8 pad1A8[0x20C - 0x1A8];
    S_66CFF8_Src *src;
} S_66CFF8_Data;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0xBC - 0x8];
    u8 bBC;
    u8 padBD[0x170 - 0xBD];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_66CFF8_State;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 bC;
    u8 bD;
    u8 padE[0x12 - 0xE];
    u8 b12[8];
    u8 pad1A[0x1C - 0x1A];
    s32 w1C;
    S_66CFF8_32 s20;
    S_66CFF8_16 s40;
    S_66CFF8_8 s50;
    S_66CFF8_8 s58;
    S_66CFF8_8 s60;
} S_66CFF8_Msg;

extern S_66CFF8_Data D_00352A40;
extern S_66CFF8_State D_001A5E50;
extern s32 D_0024073C;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_0066CFF8(s32 arg0) {
    S_66CFF8_Msg msg;
    s32 i;

    msg.bC = D_00352A40.b8;
    msg.bD = D_00352A40.bC;
    msg.w4 = D_00352A40.w0;
    msg.w8 = D_00352A40.w4;
    msg.w1C = -1;
    msg.s20 = D_00352A40.s18;
    msg.s40 = D_00352A40.s198;
    msg.s50 = D_00352A40.s38;
    msg.s58 = D_00352A40.s48;
    D_001A5E50.bBC = 0;
    msg.s60 = D_00352A40.s50;
    for (i = 0; i < 8; i++) {
        msg.b12[i] = D_00352A40.src->slots[i].b;
    }
    if (D_001A5E50.w170 == 0) {
        func_0014AD08(D_001A5E50.b7D4 | 0x40, D_001A5E50.w4, arg0, D_0024073C, sizeof(msg), &msg);
    }
}
