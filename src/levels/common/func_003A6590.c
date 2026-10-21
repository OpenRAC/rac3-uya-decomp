#include "common.h"

typedef int Q_3A6590 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A6590;

typedef struct {
    u8 pad0[0x10];
    s32 w10;
} C_3A6590;

typedef struct {
    u8 pad0[0x30];
    u8 m30[0x40];
    V4_3A6590 v70;
    V4_3A6590 v80;
    s32 f90;
    f32 f94;
    f32 f98;
} P_3A6590;

typedef struct {
    u8 pad0[0x10];
    V4_3A6590 pos;
    u8 b20;
    u8 pad21[3];
    C_3A6590 *pClass;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    P_3A6590 *pVar;
    u8 pad6C[0x98 - 0x6C];
    s32 w98;
    u8 pad9C[0xAA - 0x9C];
    s16 hAA;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0;
    u8 padB1[0xF0 - 0xB1];
    V4_3A6590 vF0;
} O_3A6590;

typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
    u8 padAC[0x100 - 0xAC];
} T_3A6590;

extern s32 D_001D545C;
extern T_3A6590 *D_001DF21C;
extern u8 D_001BBC40[];
extern s32 func_0042BB60(V4_3A6590 *);
extern void func_004243F8(O_3A6590 *, s32, s32);
extern s32 func_00435C80(T_3A6590 *);
extern s32 func_00435BE8(O_3A6590 *);
extern void func_004891A0(s32, s32, O_3A6590 *);
extern void func_00435C60(O_3A6590 *, s32);
extern void func_00488D10(s32, O_3A6590 *);
extern void func_0042C658(void *, V4_3A6590 *, V4_3A6590 *, V4_3A6590 *);

void func_003A6590(O_3A6590 *o) {
    P_3A6590 *p;
    V4_3A6590 d;
    f32 v;
    Q_3A6590 x, y, r;

    if (func_0042BB60(&o->pos) == 0) {
        return;
    }
    p = o->pVar;
    switch (o->b20) {
    case 0:
        if (p->f90 == -1) {
            func_004243F8(o, 3, -1);
            break;
        }
        if (D_001BBC40[o->bB0 + D_001D545C * 16] & 0x80) {
            func_004243F8(o, 3, -1);
            break;
        }
        p->v80 = o->pos;
        if (p->f94 != -1.0f) {
            o->pos.x = p->f94;
            o->w98 = 0;
            o->h34 |= 0x41;
        } else if (p->f98 != -1.0f) {
            o->pos.y = p->f98;
            o->w98 = 0;
            o->h34 |= 0x41;
        }
        func_004243F8(o, 1, -1);
        break;
    case 1:
        if (func_00435C80(&D_001DF21C[p->f90])) {
            o->h34 &= ~0x41;
            o->w98 = o->pClass->w10;
            func_004243F8(o, 2, -1);
        }
        break;
    case 2:
        if (func_00435BE8(o) && D_001D545C == 8 && p->f90 != -1
            && ((T_3A6590 *)((u8 *)D_001DF21C + (p->f90 << 8)))->hAA != o->hAA) {
            func_004891A0(0, 20, o);
        }
        if (p->f94 != -1.0f) {
            v = o->pos.x + ((p->f94 < p->v80.x) ? 0.1f : -0.1f);
            o->pos.x = v;
            if (fabsf(v - p->f94) >= 1.95f) {
                func_00435C60(o, 1);
            }
            if (fabsf(o->pos.x - p->v80.x) < 0.05f) {
                func_00488D10(0, o);
                func_004243F8(o, 3, -1);
            }
        } else if (p->f98 != -1.0f) {
            v = o->pos.y + ((p->f98 < p->v80.y) ? 0.1f : -0.1f);
            o->pos.y = v;
            if (fabsf(v - p->f98) >= 1.95f) {
                func_00435C60(o, 1);
            }
            if (fabsf(o->pos.y - p->v80.y) < 0.05f) {
                func_00488D10(0, o);
                func_004243F8(o, 3, -1);
            }
        }
        break;
    }
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v70));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    func_0042C658(p->m30, &d, &o->vF0, &o->vF0);
    p->v70 = o->pos;
}
