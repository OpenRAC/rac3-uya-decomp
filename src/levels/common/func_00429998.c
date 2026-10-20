#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
} S_429998e;

typedef struct {
    s32 a;
    s32 b;
} S_429998p;

typedef struct {
    u8 pad0[0x1284];
    s32 w1284;
    S_429998p e[1];
} S_429998t;

typedef struct {
    u8 pad0[0x30];
    s32 w30;
    u8 pad34[0x6C - 0x34];
    S_429998e *p6C;
    u8 pad70[0x90 - 0x70];
    u32 arr90[68];
} S_429998;

extern S_429998t D_00160C40;
extern S_429998 D_001E6E00;
extern void func_0045C8A8(S_429998e *a0, s32 a1, s32 a2);
extern void func_0045CA60(s32 a0);
extern void func_00402A10(s32 a0);

void func_00429998(s32 idx, s32 a1) {
    S_429998 *s;
    S_429998e *p;
    s32 i;

    s = &D_001E6E00;
    func_0045C8A8(s->p6C, D_00160C40.e[idx].a + D_00160C40.w1284, D_00160C40.e[idx].b);
    if (a1 != 0) {
        func_0045CA60(0);
        func_00402A10(a1);
    }
    s->w30 = idx;
    func_0045CA60(1);
    p = s->p6C;
    for (i = 0; i < 68 && p->w4 != 0; i++, p++) {
        D_001E6E00.arr90[i] = (u32)((u8 *)D_001E6E00.p6C + (p->w0 + 0x800));
    }
}
