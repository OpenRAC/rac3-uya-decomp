#include "common.h"

extern s32 D_001DFD8C;
typedef struct { s16 a; s16 b; } P_392108;
typedef struct { s32 w; s32 pad; } W_392108;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;

typedef int u128_3925F0 __attribute__((mode(TI)));
extern u8 D_001DA1B0[];
extern P_392108 *D_001DFDA0_003925F0;
extern W_392108 *D_001DFDA4_003925F0;
extern s32 D_001E10E8_003925F0;
extern s32 D_001DFD8C;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern unsigned long func_0041D950(s32);
void func_0041DD68(s32 idx, s32 x, s32 y, s32 w, s32 h, s32 *uv) {
    P_392108 *p = (P_392108 *)((idx << 2) + (s32)D_001DFDA0_003925F0);
    u8 *e = (u8 *)&D_001DFDA4_003925F0[p->b];
    s32 tw = 1 << e[6];
    s32 th = 1 << e[7];
    u8 *r;
    u8 *pk;
    u8 *q;
    *(s32 *)(D_001E10E8_003925F0 + 0) = 0x10000008;
    *(s32 *)(D_001E10E8_003925F0 + 4) = 0;
    *(s32 *)(D_001E10E8_003925F0 + 8) = 0;
    *(s32 *)(D_001E10E8_003925F0 + 0xC) = 0x50000008;
    r = (u8 *)D_001E10E8_003925F0;
    D_001E10E8_003925F0 = (s32)r + 0x10;
    *(u128_3925F0 *)(r + 0x10) = *(u128_3925F0 *)D_001DA1B0;
    pk = (u8 *)D_001E10E8_003925F0;
    q = pk + 0x10;
    D_001E10E8_003925F0 = (s32)q;
    *(unsigned long *)(pk + 0x10) = func_0041D950(idx);
    *(unsigned long *)(q + 8) = 0x15C;
    *(unsigned long *)(q + 0x10) = uv[0];
    *(unsigned long *)(q + 0x18) = 0;
    *(unsigned long *)(q + 0x20) = (unsigned long)((x << 4) + D_001D4BD0 - 8) | ((unsigned long)((y << 4) + D_001D4BD4 - 8) << 16) | ((unsigned long)D_001DFD8C << 32);
    *(unsigned long *)(q + 0x28) = uv[1];
    *(unsigned long *)(q + 0x30) = tw << 4;
    *(unsigned long *)(q + 0x38) = (unsigned long)(((x + w) << 4) + D_001D4BD0 - 8) | ((unsigned long)((y << 4) + D_001D4BD4 - 8) << 16) | ((unsigned long)D_001DFD8C << 32);
    *(unsigned long *)(q + 0x40) = uv[2];
    *(unsigned long *)(q + 0x48) = th << 20;
    *(unsigned long *)(q + 0x50) = (unsigned long)((x << 4) + D_001D4BD0 - 8) | ((unsigned long)(((y + h) << 4) + D_001D4BD4 - 8) << 16) | ((unsigned long)D_001DFD8C << 32);
    *(unsigned long *)(q + 0x58) = uv[3];
    *(unsigned long *)(q + 0x60) = (th << 20) + (tw << 4);
    *(unsigned long *)(q + 0x68) = (unsigned long)(((x + w) << 4) + D_001D4BD0 - 8) | ((unsigned long)(((y + h) << 4) + D_001D4BD4 - 8) << 16) | ((unsigned long)D_001DFD8C << 32);
    D_001E10E8_003925F0 = D_001E10E8_003925F0 + 0x70;
}
