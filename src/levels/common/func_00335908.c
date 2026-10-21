#include "common.h"

/* localdecomp:start func_00335908 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[0x4];
    struct M_335908 *p24;
    u8 p28[0x8];
    u8 b30;
    u8 b31;
    u16 h32;
    u16 h34;
    u8 p36[0x2];
    long d38;
    u8 p40[0x58];
    s32 i98;
    u8 p9C[0x1C];
    void *pB8;
    u8 pBC[0x34];
    u128_t qF0;
} O_335908;
typedef struct M_335908 {
    u8 p0[0x10];
    s32 i10;
    u8 p14[0x30];
    u16 h44;
    u8 b46;
} M_335908;
typedef struct {
    u8 p0[0x68];
    struct C_335908 *c;
} A_335908;
typedef struct C_335908 {
    u8 p0[0x40];
    s32 i40;
    u8 p44[4];
    s32 i48;
} C_335908;
typedef struct {
    void *p0;
    u8 p4[4];
    void *p8;
    void *pC;
    void *p10;
    u8 p14[8];
    void *p1C;
    u8 p20[0x450];
    s32 i470;
} S_335908;
typedef struct {
    u8 p0[0x94];
    S_335908 *(*fn94)(void *);
    s32 (*fn98)(void);
} F_335908;

extern s16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern s32 D_001E00D8;
extern F_335908 *func_00438488(s32 a, s32 b, s32 c);
extern u8 *func_00435E70(s32 a, s32 b);
extern void func_00441BA0(void *a, s32 b, s32 c);
extern void func_0040BBA8(void *a, s32 b, s32 c);

u8 *func_00335908(O_335908 *a0) {
    C_335908 *c;
    F_335908 *f;
    O_335908 *o;
    S_335908 *s;
    s16 *p;
    s32 found;

    o = 0;
    s = 0;
    c = ((A_335908 *)a0)->c;
    f = func_00438488(c->i40, 4, 156);
    if (c->i48 != -1) {
        found = 0;
        for (p = D_0021DEA0[c->i48];
             (c->i48 & 0xFF) != 0xFF && c->i48 <= D_001E00D8 && p != 0 &&
             (p[-1] >= 0 || p == D_0021DEA0[c->i48]);
             p++) {
            o = (O_335908 *)(D_001E009C + ((*p & 0x7FFF) << 8));
            if (o == 0) {
                break;
            }
            s = f->fn94(o);
            if (*(s16 *)((u8 *)o + 170) == c->i40 && s->i470 == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
        if (o != 0) {
            o->h34 &= 0xFFBC;
            o->h34 |= o->p24->h44 & 0x1000;
            o->i98 = o->p24->i10;
        }
    } else {
        o = (O_335908 *)func_00435E70(c->i40, f->fn98());
        s = f->fn94(o);
    }
    o->b30 = a0->b30;
    o->h32 = 128;
    o->b31 = 1;
    if (a0->h34 & 0x80) {
        o->h34 |= 0x80;
    } else {
        o->h34 &= 0xFF7F;
    }
    func_00441BA0(o, 0, 0);
    if (a0 != 0) {
        o->pB8 = a0;
        o->q10 = a0->q10;
        o->qF0 = a0->qF0;
        o->d38 = a0->d38;
    }
    if (c->i48 == -1) {
        func_0040BBA8(s, 0, 1232);
        o->h34 |= 0x20;
        s->p0 = (u8 *)s + 48;
        s->p8 = (u8 *)s + 112;
        s->pC = (u8 *)s + 176;
        s->p10 = (u8 *)s + 208;
        s->p1C = (u8 *)s + 400;
    }
    s->i470 = 1;
    o->p24->b46 = 14;
    o->h34 &= 0xEFFF;
    return (u8 *)o;
}
/* localdecomp:end func_00335908 */
