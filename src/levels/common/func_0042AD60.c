#include "common.h"

/* localdecomp:start func_0042AD60 */
typedef struct {
    s32 a;
    s32 b;
    s32 p;
    s32 pad;
} E_42AD60;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
    s32 w16;
    s32 w20;
    u8 pad18[40 - 24];
    s32 w40;
    u8 pad2c[48 - 44];
    E_42AD60 e[8];
    u8 padB0[180 - 176];
    f32 f180[61];
    s32 a424[61];
    s32 a668[61];
    u8 pad390[1040 - 912];
    s32 idx;
    u8 pad414[1048 - 1044];
    s32 w1048;
    s32 w1052;
    s32 w1056;
} G_42AD60;

typedef struct {
    s32 off;
    s32 size;
} P_42AD60;

typedef struct {
    u8 pad0[18772];
    s32 base;
    u8 pad4958[24008 - 18776];
    P_42AD60 a[60];
    P_42AD60 b[60];
} T_42AD60;

extern G_42AD60 D_001F4020;
extern P_42AD60 D_002E7238[];
extern s32 D_001D545C;
extern T_42AD60 D_00160C40;
extern u8 D_00142CA0[];
extern s32 *D_001EA9D0[];
extern char D_001D7120[];
extern char D_001D7138[];
extern u8 D_001A9318[];
extern u8 D_001F43B0[];

extern s32 func_0042B958(s32);
extern s32 func_0045CA00(s32 *, s32, s32);
extern s32 func_004AD500(s32 *, s32, s32, char *);
extern s32 func_00433EA0(s32 *, s32 *);
extern s32 func_0041A098(s32, s32, char *, s32);
extern void func_0040BD58(s32, void *, s32);
extern s32 func_0042AD18(s32);
extern void func_0042DBF0(s32, u8 *, s32);
extern void func_0042D020(s32, s32, s32);

void func_0042AD60(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 n;
    s32 *data;
    s32 *dst;
    s32 sz;
    char *str;
    s32 sz2;
    f32 dy;
    f32 dx;
    f32 r2;
    f32 c;

    D_001F4020.w16 = 1;
    for (i = 0; i < 61; i++) {
        D_001F4020.a424[i] = D_002E7238[i].off;
        D_001F4020.f180[i] = 0.65f;
        D_001F4020.a668[i] = D_002E7238[i].size;
    }
    D_001F4020.w1048 = -1;
    func_0042B958(D_001D545C);
    if ((D_00160C40.a[D_001F4020.idx].size != 0 && D_00142CA0[5] == 0) || (D_00160C40.b[D_001F4020.idx].size != 0 && D_00142CA0[5] != 0)) {
        D_001F4020.w40 = 1;
        n = (D_00142CA0[5] != 0 ? D_00160C40.b[D_001F4020.idx].size : D_00160C40.a[D_001F4020.idx].size) << 7;
        data = D_001EA9D0[0];
        dst = (s32 *)((u8 *)data + 0x9A800);
        if (D_00142CA0[5] != 0) {
            func_0045CA00(dst, D_00160C40.b[D_001F4020.idx].off + D_00160C40.base, D_00160C40.b[D_001F4020.idx].size);
            D_001F4020.w1052 = 1;
        } else {
            func_0045CA00(dst, D_00160C40.a[D_001F4020.idx].off + D_00160C40.base, D_00160C40.a[D_001F4020.idx].size);
            D_001F4020.w1052 = 0;
        }
        D_001F4020.w1048 = func_004AD500(dst, n, 16640, D_001D7120);
        str = D_001D7138;
        D_001F4020.w1056 = n;
        func_00433EA0(dst, data);
        sz = data[1] - data[0];
        D_001F4020.w0 = func_0041A098(sz, 0, str, 876);
        func_0040BD58(D_001F4020.w0, (u8 *)data + data[0], sz);
        D_001F4020.w0 += 8;
        D_001F4020.w4 = D_001F4020.w0;
        sz2 = data[2] - data[1];
        D_001F4020.w20 = func_0041A098(sz2, 0, str, 893);
        func_0040BD58(D_001F4020.w20, (u8 *)data + data[1], sz2);
        D_001F4020.w8 = func_0041A098(4096, 0, str, 900);
        for (j = 0; j < 8; j++) {
            D_001F4020.e[j].a = -1;
            D_001F4020.e[j].b = -1;
            D_001F4020.e[j].p = D_001F4020.w8 + (j << 9);
        }
        D_001F4020.w12 = func_0041A098(0x8000, 0, D_001D7138, 909);
        if (func_0042AD18(D_001F4020.idx)) {
            func_0042DBF0(D_001F4020.w12, D_001A9318 + (D_001F4020.idx << 11), D_001F4020.w20);
        } else {
            func_0042D020(D_001F4020.w12, D_001F4020.w0, D_001F4020.w4);
        }
        r2 = 256.0f;
        c = 15.5f;
        for (y = 0; y < 32; y++) {
            dy = c - y;
            for (x = 0; x < 32; x++) {
                dx = c - x;
                if (r2 < dx * dx + dy * dy) {
                    D_001F43B0[x / 8 + y * 4] |= 1 << (x % 8);
                }
            }
        }
    } else {
        D_001F4020.w0 = 0;
        D_001F4020.w8 = 0;
        D_001F4020.w12 = 0;
        D_001F4020.w4 = 0;
        D_001F4020.w40 = 0;
    }
}
/* localdecomp:end func_0042AD60 */
