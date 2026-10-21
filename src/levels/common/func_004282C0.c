#include "common.h"

/* localdecomp:start func_004282C0 */
typedef struct E_4282C0 {
    s32 a;
    s32 b;
} E_4282C0;
typedef struct T_4282C0 {
    u8 pad0[0x79A4];
    s32 f79A4;
    u8 pad1[0x28];
    E_4282C0 e[1];
} T_4282C0;
typedef struct S_4282C0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_4282C0;
extern S_4282C0 D_001F3FC0;
extern f32 D_001DF9D0;
extern s32 D_001E10F4;
extern s32 D_001E10E8;
extern s32 *D_001E10E0[];
extern T_4282C0 D_00160C40;
extern s32 D_001E0F14;
extern u8 *D_001E0F10;
extern void func_004A7798(s32, s32, s32, s32, s32);
extern void func_004A7810(void);
extern void func_0045BEC8(void);
extern void func_00402A10(s32);
extern void func_004C1E50(s32);
extern void func_004223F0(void);
extern void func_0045CA00(void *, s32, s32);
extern void func_0011F0A0(s32);
extern void func_00433EA0(void *, s32);
extern void func_00424DE8(s32, s32);
extern void func_004250B0(s32);
extern void func_004AEC50(s32);
extern void func_004AF9A8(void);
extern void func_00428088(void);
extern void func_0045B468(s32);
extern void func_004281A8(s32);
extern void func_0045BB60(s32, s32, s32);
extern s32 func_00457270(s32);
extern void func_0045BF98(s32);
void func_004282C0(s32 a0, s32 a1) {
    S_4282C0 *g;
    s32 *x;
    u8 *y;
    u8 *z;
    T_4282C0 *q;
    s32 n;
    s32 i;
    s32 j;
    u16 *p;
    if (D_001F3FC0.f0 != a0) {
        func_004A7798(0, 0, 0, 0, 0);
        func_004A7810();
        func_0045BEC8();
        if (D_001DF9D0 >= 0.75f) {
            func_00402A10(2);
        } else {
            func_004C1E50(1);
        }
        D_001F3FC0.f0 = a0;
        g = &D_001F3FC0;
        x = D_001E10E0[0];
        D_001E10E8 = (s32)D_001E10E0[D_001E10F4];
        func_004223F0();
        q = &D_00160C40;
        func_0045CA00(x, q->e[a0].a + q->f79A4, q->e[a0].b);
        y = (u8 *)x + x[0];
        z = (u8 *)x + x[1];
        func_0011F0A0(0);
        func_00433EA0(y, g->f8);
        func_00433EA0(z, g->f4);
        func_0011F0A0(0);
        func_00424DE8(g->f8, g->f10);
        func_004250B0(g->f4);
        n = D_001E0F14;
        if (n > 0) {
            u8 *q = D_001E0F10 + 0x36;
            for (; n != 0; n--) {
                *(u16 *)q = 0xFFFF;
                q += 0x40;
            }
        }
        i = 0;
        while (i < D_001E0F14) {
            p = (u16 *)0x70003000;
            for (j = 0; j < 0x3FF && i < D_001E0F14; j++) {
                *p++ = i;
                i++;
            }
            *p = 0xFFFF;
            func_004AEC50(0x70003000);
        }
        func_004AF9A8();
        func_00428088();
        func_0045B468(a0);
        func_004281A8(a0);
        func_0045BB60(a1, 1, 0x400);
        if (func_00457270(2) != 0) {
            func_0045BF98(0);
        }
    }
}
/* localdecomp:end func_004282C0 */
