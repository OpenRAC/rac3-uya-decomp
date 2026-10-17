#include "common.h"

extern s16 *D_0021C6A0[];
extern u8 *D_001DFA1C;
extern void func_004405E0(u8 *, s32);

void func_0042FC00(s32 a0, s32 a1) {
    s16 *list = D_0021C6A0[a0];
    s16 *p;
    if (list != 0) {
        p = list;
        do {
            func_004405E0(D_001DFA1C + ((*p & 0x7fff) << 8), a1);
        } while (*p++ >= 0);
    }
}
