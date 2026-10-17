#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    u128_t v10;
    u8 pad20[0x3];
    u8 b23;
    u8 pad24[0xC];
    u8 b30;
    u8 b31;
    u16 h32;
    u16 h34;
    u8 pad36[0xF0 - 0x36];
    u128_t vF0;
} O_64C050;

typedef struct {
    u8 pad0[0xA0];
    u128_t vA0;
    u128_t vB0;
    u8 padC0[0x120 - 0xC0];
    f32 v120[2];
    s32 w128;
    u8 pad12C[0x13F4 - 0x12C];
    O_64C050 *o13F4;
    u8 pad13F8[0x2524 - 0x13F8];
    O_64C050 *o2524;
} S_64C050;

extern O_64C050 *func_005A8280(s32, s32);
extern void func_005AB3B0(O_64C050 *);
extern s32 func_005F0CE0(s32, s32, O_64C050 *);
extern f32 func_0058F430(f32 *);
extern void func_0058F6B8(f32 *, f32 *, f32);
extern void func_00635068(S_64C050 *);

void func_0064C050(S_64C050 *p) {
    if (p->o13F4 == 0) {
        p->o13F4 = func_005A8280(1322, 128);
        if (p->o13F4 != 0) {
            p->o13F4->v10 = p->vA0;
            p->o13F4->vF0 = p->vB0;
            p->o13F4->h32 = 64;
            p->o13F4->b31 = 1;
            p->o13F4->b30 = 0;
            p->o13F4->b23 = 0;
            p->o13F4->h34 |= 0x800;
            func_005AB3B0(p->o13F4);
            func_005F0CE0(0, 0, p->o13F4);
        }
    }
    if (p->o13F4 != 0) {
        p->o13F4->b23 += 5;
        if (p->o13F4->b23 > 128) {
            p->o13F4->b23 = 128;
        }
        p->o13F4->v10 = p->o2524->v10;
        p->o13F4->vF0 = p->o2524->vF0;
        func_005AB3B0(p->o13F4);
    }
    p->w128 = 0;
    func_0058F6B8(p->v120, p->v120, func_0058F430(p->v120) * 0.92f);
    func_00635068(p);
}
