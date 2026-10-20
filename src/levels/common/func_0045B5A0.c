#include "common.h"

typedef struct { s32 a; s32 b; } P_45B5A0;
typedef struct { P_45B5A0 p[41]; u8 pad[4]; } E_45B5A0;
typedef struct {
    u8 p0[4740];
    s32 f4740;
    u8 p1[3056];
    P_45B5A0 t5000[122];
    u8 p2[4];
    s32 f8780;
    s32 t1000[254];
} G_45B5A0;
typedef struct {
    u8 p0[31236];
    s32 f31236;
    P_45B5A0 t3000[770];
    u8 p3[4];
    s32 f37404;
} G2_45B5A0;
typedef struct { u8 p0[183]; u8 b183; } S_45B5A0;

extern G_45B5A0 D_00160C40;
extern G2_45B5A0 D_00160C40_0045B5A0;
extern u8 D_00143A07[];
extern S_45B5A0 D_00143950;
extern E_45B5A0 D_0001DBC0[];
extern E_45B5A0 D_0001DBC4[];
typedef struct { s32 t[1][400]; u8 p0[26980 - 1600]; s32 f26980; } T_45B5A0;
extern T_45B5A0 D_0015C528;
extern E_45B5A0 D_00169E60[];
extern E_45B5A0 D_00169E64[];

static inline s32 gi(void) { s32 x = D_00143A07[0]; if (x) x--; return x; }

void func_0045B5A0(s32 id, s32 *out1, s32 *out2) {
    *out1 = 0;
    *out2 = 0;
    if (id >= 7000) {
        s32 idx = gi();
        s32 v = D_0015C528.t[idx][id];
        if (v) *out1 = v + D_0015C528.f26980;
        return;
    }
    if (id >= 6000) {
        s32 idx = gi() - 6000;
        s32 v = D_00160C40_0045B5A0.t3000[id + idx].a;
        if (v) *out1 = D_00160C40_0045B5A0.f31236 + v;
        return;
    }
    if (id >= 5000) {
        s32 v = D_00160C40.t5000[id - 5000].a;
        if (v) *out1 = D_00160C40.f4740 + v;
        return;
    }
    if (id >= 4000) {
        s32 v = *(s32 *)((u8 *)D_0001DBC0 + id * 332 + D_00143950.b183 * 8);
        s32 w;
        if (v == 0) return;
        *out1 = D_00160C40.f4740 + v;
        w = *(s32 *)((u8 *)D_0001DBC4 + D_00143950.b183 * 8 + id * 332);
        if (w) *out2 = D_00160C40.f4740 + w;
        return;
    }
    if (id >= 3000) {
        s32 v = D_00160C40_0045B5A0.t3000[id - 3000].a;
        if (v) *out1 = D_00160C40_0045B5A0.f31236 + v;
        return;
    }
    if (id >= 2000) {
        s32 idx = gi() - 2000;
        s32 v = D_00160C40_0045B5A0.t3000[id + idx].a;
        if (v) *out1 = D_00160C40_0045B5A0.f31236 + v;
        return;
    }
    if (id >= 1000) {
        s32 idx = gi() - 1000;
        s32 v = D_00160C40.t1000[id + idx];
        if (v) *out1 = D_00160C40.f8780 + v;
        return;
    }
    {
        s32 v = *(s32 *)((u8 *)D_00169E60 + id * 332 + D_00143950.b183 * 8);
        s32 w;
        if (v == 0) return;
        *out1 = D_00160C40_0045B5A0.f37404 + v;
        w = D_00169E64[id].p[D_00143950.b183].a;
        if (w) *out2 = D_00160C40_0045B5A0.f37404 + w;
    }
}
