#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_31DE60;

typedef struct {
    u8 pad0[0x1210];
    s32 i1210;
    u8 pad1214[0x1220 - 0x1214];
    s32 i1220;
    u8 pad1224[0x1430 - 0x1224];
    u8 *p1430;
    u8 pad1434[0x25C4 - 0x1434];
    s32 i25C4;
    u8 pad25C8[0x25E9 - 0x25C8];
    u8 b25E9;
    u8 pad25EA[3];
    u8 b25ED;
    u8 pad25EE[0x28BC - 0x25EE];
    s32 i28BC;
} S_31DE60;

typedef struct {
    u8 pad0;
    u8 b1;
    u8 pad2[0x50 - 2];
    f32 f50;
    u8 pad54[0xF0 - 0x54];
} E_31DE60;

extern void func_0031E2F8(u8 *m, V4_31DE60 *out);
extern void func_0031E348(u8 *m, V4_31DE60 *a, V4_31DE60 *b);
extern void func_0031E388(u8 *m, V4_31DE60 *a, V4_31DE60 *b);
extern void func_0031E508(void);
extern s32 func_003C9058(void *a, s32 b);
extern void func_003C9278(s32 a, s32 b);
extern void func_003DB580(void (*fn)(void), u8 *m);
extern s32 func_003E4190(s32 *t);
extern void func_003E4220(f32 *t);
extern f32 *func_00418190(u8 *p);
extern void func_004197B8(u8 *m, s32 a, s32 b, s32 c, s32 d);
extern s32 func_0047D488(s32 a, s32 b, u8 *m);
extern void func_00499960(V4_31DE60 *out, V4_31DE60 *in, u8 *tgt, s32 d, f32 a, f32 b, f32 c, f32 e);
extern s32 func_00499F40(V4_31DE60 *a, V4_31DE60 *b, u8 *v, u8 *w, u8 *m, s32 x, s32 y, f32 f);
extern void func_004BBDD8(s32 a);
extern void func_004BC080(void);
extern void func_004CF3B8(s32, s32);
extern void func_004DDB28(s32 a, s32 b);
extern s32 func_004DDC38(s32 a);
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern S_31DE60 D_001A4BE0;
extern u8 *D_001D52FC;
extern s32 D_001D6694;
extern s32 D_001E01D0;
extern u8 D_002AD5C0[];
extern E_31DE60 D_002C3200[];

void func_0031DE60(u8 *m) {
    V4_31DE60 a;
    V4_31DE60 b;
    u8 *v;
    u8 *tgt;
    s32 ok;
    s32 live;
    f32 *r;

    v = *(u8 **)(m + 0x68);
    if (m[0x20] == 0) {
        m[0x20] = 1;
        *(s32 *)(v + 0x28) = -1;
        *(s32 *)(v + 0x20) = 0;
        *(s32 *)(v + 0x2C) = 0;
        D_001E01D0 = 20;
    }
    if (D_001A4BE0.i25C4 == 1) {
        func_004CF3B8(0x1D, 1);
    }
    if (D_002C3200[D_001425C0[0x13]].b1 >= 2) {
        D_00142A60[0x13] |= 0x20;
    }
    if (m[0x42] == m[0x43] && (m[0x60] & 2)) {
        func_004197B8(m, 1, 0, 2, 0);
    }
    func_0031E2F8(m, &a);
    tgt = 0;
    if (D_001A4BE0.p1430 != 0 && D_001A4BE0.p1430[0x20] != 0xFE && D_001A4BE0.p1430[0x20] != 0xFD) {
        r = func_00418190(D_001A4BE0.p1430);
        if (r != 0 && *r > 0.0f) {
            tgt = D_001A4BE0.p1430;
        }
    }
    ok = 1;
    if (D_001A4BE0.i25C4 == 0x1D) {
        if (func_003E4190(&D_001A4BE0.i28BC) == 0) {
            ok = 0;
        }
    } else {
        D_001A4BE0.i28BC = 0x28;
    }
    func_00499960(&b, &a, tgt, 0, 1.6f, 10.0f, 0.25f, 0.004055556f);
    *(s32 *)(v + 0x24) = func_00499F40(&a, &b, v, v + 0x10, m, 0, 0, 0.004055556f);
    live = 1;
    if (*(f32 *)(v + 0x20) <= 0.0f) {
        live = 0;
    }
    func_003E4220((f32 *)(v + 0x20));
    if (live && *(f32 *)(v + 0x20) <= 0.0f && func_004DDC38(-1)) {
        func_0047D488(3, 0, m);
    }
    if (*(s32 *)(v + 0x2C) != 0 && func_003E4190((s32 *)(v + 0x2C))) {
        func_004BC080();
    }
    if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0.i1210) && !func_004DDC38(-1)) {
        func_0047D488(1, 0, m);
        D_001E01D0 = 20;
    }
    if (D_001D6694 == 0 && *(f32 *)(v + 0x20) == 0.0f && D_001A4BE0.b25ED == 0 && m[0x42] < 2
        && (*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.i1210) && D_001A4BE0.i1220 >= 0x17 && ok) {
        if (func_004DDC38(-1)) {
            func_0047D488(0, 0, m);
            func_004DDB28(-1, 1);
            func_0031E388(m, &a, &b);
            func_004197B8(m, 2, 0, 2, 0);
            func_0031E348(m, &a, &b);
            func_004BBDD8(-1);
            *(s32 *)(v + 0x2C) = 0x10;
            *(s32 *)(v + 0x28) = func_003C9058(D_002AD5C0, 0);
        }
        if (!((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.i1210) && func_004DDC38(-1) && D_001A4BE0.b25E9 != 0)) {
            if (*(s32 *)(v + 0x28) >= 0) {
                func_003C9278(*(s32 *)(v + 0x28), 0);
                *(s32 *)(v + 0x28) = -1;
            }
        }
        {
            E_31DE60 *e = &D_002C3200[D_001425C0[0x13]];
            *(f32 *)(v + 0x20) = 1.0f / e->f50;
        }
    }
    func_003DB580(func_0031E508, m);
}
