#include "common.h"

typedef int u128_3B5048 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } C_3B5048;
typedef struct { u8 p0[0x81]; u8 b81; u16 h82; } V_3B5048;
typedef struct {
    u8 p0[0x10]; u128_3B5048 pos; u8 b20; u8 b21; u8 p22[2]; C_3B5048 *w24; u8 p28[8];
    u8 b30; u8 b31; u16 h32; u16 h34; u8 p36[0x32]; V_3B5048 *w68; u8 p6C[0x13]; u8 b7F; u8 p80[0x15]; u8 b95;
    u8 p96[2]; s32 w98; u8 p9C[0x24]; u8 vC0[0x30]; u128_3B5048 vF0;
} M_3B5048;
typedef struct { f32 f0; s16 h4; } A_3B5048;
typedef struct { s16 h0; s16 h2; u8 b4; u8 b5; u8 b6; u8 p7[0x13]; u8 b1A; u8 p1B[0x1D]; s16 h38; } B_3B5048;
typedef struct { u8 p0[8]; void *w8; } E_3B5048;
extern void func_0040C638(void *, void *);
extern E_3B5048 *func_00445F18(M_3B5048 *);
extern void func_00441BA0(M_3B5048 *, s32, s32);
extern A_3B5048 *func_00440728(M_3B5048 *);
extern void func_003265F0(M_3B5048 *, A_3B5048 *);
extern B_3B5048 *func_00445EB8(M_3B5048 *);
extern void func_00438908(M_3B5048 *, s32, s32, s32);

void func_003B5048(void *owner, M_3B5048 *m, M_3B5048 *src) {
    C_3B5048 *c;
    A_3B5048 *a;
    B_3B5048 *b;
    m->b7F = 0;
    if (owner != 0) {
        m->b21 = 255;
    }
    if (src != 0) {
        V_3B5048 *v = src->w68;
        m->b30 = v->b81;
        m->h32 = v->h82;
        m->pos = src->pos;
        m->vF0 = src->vF0;
        func_0040C638(m->vC0, &m->vF0);
    }
    func_00445F18(m)->w8 = owner;
    m->b20 = 0;
    m->h34 &= ~2;
    c = m->w24;
    m->b95 = 0;
    if (c != 0) {
        m->h34 &= ~0x45;
        m->h34 |= c->h44 & 0x1000;
        m->w98 = c->w10;
        m->b31 = 1;
        func_00441BA0(m, 0, 0);
    }
    a = func_00440728(m);
    if (a != 0) {
        if (src != 0) {
            func_003265F0(m, a);
        }
        a->f0 = a->h4;
    }
    b = func_00445EB8(m);
    if (b != 0) {
        b->b1A = 0;
        b->h38 = 0;
        if (b->h0 != 0) {
            b->h0 = 0;
            func_00438908(m, b->b4, b->b5, b->b6);
            b->h2 = 1;
        }
    }
}
