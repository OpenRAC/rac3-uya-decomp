#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_4C1988;
typedef struct { u8 p0[0x80]; s32 f80; s32 f84; u8 p88[0xBC]; E_4C1988 e[1]; } S_4C1988;
extern S_4C1988 D_00244740[];
extern s32 D_001E1000;
extern s32 func_0044F480(void);
extern s32 func_004181A0(s32);
extern s32 func_00512FE8(s32, s32);
extern s32 func_00512AB0(s32, s32, s32);

void func_004C1988(void) {
    S_4C1988 *b = D_00244740;
    s32 n = b->e[b->f80].f0;

    if (b->f84 == 0) {
        if (n != 0) {
            func_00512FE8(0x480012, func_004181A0(2252));
        }
        func_00512FE8(0x480013, func_004181A0(256));
        func_00512AB0(0x48000D, 1, 0);
        if (D_001E1000 == 0) {
            func_00512AB0(0x48000C, 1, 1);
        }
    } else {
        if (func_0044F480() >= n) {
            func_00512FE8(0x480012, func_004181A0(2274));
            func_00512FE8(0x480013, func_004181A0(2271));
            func_00512FE8(0x48000D, func_004181A0(2256));
        } else {
            func_00512FE8(0x48000D, func_004181A0(2255));
        }
        func_00512AB0(0x48000D, 1, 1);
        func_00512AB0(0x48000C, 1, 0);
    }
}
