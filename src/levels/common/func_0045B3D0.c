#include "common.h"

extern void func_0045B3D0(s32);
extern void func_0045B360();

typedef struct { u8 pad[0x90]; u32 a[1]; u32 b[1]; } S_39C210;
typedef struct { s32 v; s32 w; } E_39C210;
typedef struct { u8 pad0[0x79A4]; s32 f79A4; u8 pad1[0x79E8 - 0x79A8]; E_39C210 e[1]; } G_39C210;
extern S_39C210 D_001A30B0_0039C210[];
extern G_39C210 D_00160C40_0039C210[];
extern void func_0045B360();
extern void func_0013BAB8(s32, s32, void *, unsigned long);
void func_0045B3D0(s32 idx) {
    G_39C210 *g = D_00160C40_0039C210;
    s32 v = g->e[idx].v;
    S_39C210 *s;
    u32 *q;
    if (v) {
        s = D_001A30B0_0039C210;
        q = s->b;
        s->a[idx + 1] = 0xFFFFFFFF;
        func_0013BAB8(v + g->f79A4, 0, func_0045B360, (u32)(q + idx));
    } else {
        D_001A30B0_0039C210->a[idx + 1] = 0;
    }
}
