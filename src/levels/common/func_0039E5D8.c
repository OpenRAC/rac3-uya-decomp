#include "common.h"

/* localdecomp:start func_0039E5D8 */
typedef int u128_39E5D8 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 w10; } C_39E5D8;
typedef struct {
    s32 w0; u8 p4[0x35]; u8 b39; u8 p3A[0x3A];
    s16 h74; s16 h76; u8 p78[4]; s32 w7C; s32 w80; u8 p84[4]; f32 f88; u8 p8C[4];
    s32 w90; s32 w94; s32 w98; u8 p9C[8]; s32 wA4; s32 wA8;
} V_39E5D8;
typedef struct {
    u8 p0[0x10];
    u128_39E5D8 pos;
    u8 b20;
    u8 p21[3];
    C_39E5D8 *w24;
    u8 p28[8];
    u8 b30; u8 b31;
    s16 h32;
    u16 h34;
    u8 p36[0x12];
    f32 f48;
    u8 p4C[0x1C];
    V_39E5D8 *w68;
    u8 p6C[0x2C];
    s32 w98;
    u8 p9C[0x54];
    u128_39E5D8 rF0;
} M_39E5D8;
typedef struct { u8 p0[0x10]; u128_39E5D8 pos; u8 p20[0x8A]; s16 hAA; u8 pAC[0x14]; u8 rC0[0x10]; } A_39E5D8;
typedef struct { u8 p0[0xE]; u8 bE; u8 pF[8]; u8 b17; } T_39E5D8;
typedef struct { u8 b0; u8 b1; u8 p2[238]; } S_002C5640;
extern M_39E5D8 *func_00435E70(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_00438908(M_39E5D8 *, s32, s32, s32);
extern void func_0040C8A0(void *, void *);
extern void func_00447748(void *, void *);
extern f32 func_0040C490(f32, f32);
extern s32 func_00440878(s32, s32);
extern void func_003D2D28(M_39E5D8 *);
extern T_39E5D8 *func_00440728(A_39E5D8 *);
extern void func_00456960(s32);
extern void func_004412D0(A_39E5D8 *, s32, s32);
extern void func_00436220(A_39E5D8 *);
extern void func_00439610(M_39E5D8 *);
extern s32 D_001D6740;
extern s32 D_001D673C;
extern f32 D_001A4BE0[];
extern u8 D_001425C0[];
extern S_002C5640 D_002C5640[];
extern s32 D_001D545C;
extern s32 D_001D67B0;
M_39E5D8 *func_0039E5D8(A_39E5D8 *a) {
    M_39E5D8 *m;
    V_39E5D8 *v;
    T_39E5D8 *t;
    u8 mtx[64];
    f32 f;
    m = func_00435E70(6299, 192);
    if (m != 0) {
        m->b30 = 127;
        m->h32 = 127;
        m->b31 = 1;
        v = m->w68;
        m->f48 = func_004408C0(0.85f, 1.15f);
        m->h34 |= 0x20;
        func_00438908(m, 64, 16, 16);
        *(volatile u128_39E5D8 *)&m->pos = a->pos;
        if (D_001D6740 != 0 || D_001D673C != 0) {
            func_0040C8A0(mtx, a->rC0);
            func_00447748(mtx, &m->rF0);
        } else {
            __asm__("sq $0,%0" : "=m"(m->rF0));
            ((f32 *)&m->rF0)[2] = func_0040C490(*(f32 *)&m->pos - D_001A4BE0[32], ((f32 *)&m->pos)[1] - D_001A4BE0[33]);
        }
        m->b20 = 1;
        v->h76 = 0;
        v->h74 = func_00440878(120, 300);
        v->w90 = 600;
        v->w94 = 15;
        v->w7C = 0;
        v->w98 = 0;
        if ((D_002C5640 + D_001425C0[143])->b1 >= 4) {
            v->wA4 = 1;
        } else {
            v->wA4 = 0;
        }
        if (D_001D673C != 0) {
            m->b20 = 10;
        } else {
            m->b20 = 4;
        }
        v->w0 = (s32)v + 48;
        v->b39 = 1;
        m->w98 = m->w24->w10;
        func_003D2D28(m);
        v->wA8 = func_00440878(100, 350);
        f = 1.0f;
        if ((D_002C5640 + D_001425C0[143])->b1 != 0) {
            f = 4.0f;
        }
        v->f88 = f;
        v->w80 = -1;
        t = func_00440728(a);
        if (t != 0) {
            t->b17 = 143;
        }
        if (D_001D545C == 5 && a->hAA == 6619) {
            if (++D_001D67B0 >= 15) {
                func_00456960(7);
            }
        }
        if (m->h34 & 0x1000) {
            func_004412D0(a, 0, 3);
        }
        if (t != 0 && t->bE == 1) {
            t->bE = 2;
        } else {
            func_00436220(a);
        }
        func_00439610(m);
    }
    return m;
}
/* localdecomp:end func_0039E5D8 */
