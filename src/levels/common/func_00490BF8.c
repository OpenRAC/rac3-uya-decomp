#include "common.h"

extern void func_00433EA0(u8 *, u32);
void func_00433EA0(u8 *, u32);
extern s32 func_0045C8A8(s32, s32, s32);
extern s16 D_001CCFD4[];

s32 func_00490BF8(s32 *p) {
    s32 s = p[0];
    if ((s ^ 0x10) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 *e = (s32 *)(p[7] * 8 + p[5]);
            func_0045C8A8(p[3], e[0] + p[6], e[1]);
            p[0] = 4;
        }
    } else if ((s ^ 8) == 0) {
        if (D_001CCFD4[0] == 0) {
            p[0] = 1;
        }
    } else if ((s ^ 4) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 v = 2;
            if (p[4] != 0) {
                func_00433EA0((u8 *)p[3], p[4]);
            }
            p[0] = v;
        }
    }
    return 1;
}
