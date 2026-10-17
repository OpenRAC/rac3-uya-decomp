#include "common.h"

typedef struct { s16 f0; u8 p0[0x16]; u16 f18; u8 p1[0x12]; s16 f2c; u8 p2[2]; } E39A040;
extern E39A040 *D_002E9A30_0039A040[];
extern u8 D_00143B30_0039A040[];
extern u8 D_00143BF0_0039A040[];
extern u8 D_00143CB0_0039A040[];
extern s32 func_00435A98(u8 *, s32, s32);
extern s32 func_00435C20(u8 *, s32, s32);
void func_00434550(s32 a, s32 b) {
    E39A040 *p = &D_002E9A30_0039A040[a][b];
    if (!(p->f18 & 2)) {
        if (p->f2c == 1) {
            func_00435A98(((p->f0 & 0xFF00) >> 8) == 1 ? D_00143B30_0039A040 : D_00143BF0_0039A040, a, b);
        } else if (p->f2c == 2) {
            func_00435C20(((p->f0 & 0xFF00) >> 8) == 1 ? D_00143B30_0039A040 : D_00143BF0_0039A040, a, b);
            func_00435A98(D_00143CB0_0039A040, a, b);
        }
    }
}
