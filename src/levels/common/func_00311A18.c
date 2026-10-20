#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;

typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;

extern s32 func_00454168(s32 a0, s32 a1);
extern void func_003116F0();
extern void func_00436220(S_311A18 *a0);
extern s32 func_0040D0C0(s128 *a0, f32 f12);
extern void func_00311AF8(S_311A18 *a0);
extern void func_00311D40(S_311A18 *a0);
extern void func_00311970(S_311A18 *a0);
extern void func_00311F80(S_311A18 *a0);
extern void func_003123D8(S_311A18 *a0);
extern void func_00312A80(S_311A18 *a0);

void func_00311A18(S_311A18 *o) {
    S_311A18m *m;
    s128 v;

    m = o->p68;
    if (o == 0) {
        return;
    }
    if (o->b20 == 254) {
        return;
    }
    if (o->b20 == 253) {
        return;
    }
    if (m == 0) {
        return;
    }
    if (func_00454168(o->hAA, m->w28) == 0) {
        func_003116F0();
        func_00436220(o);
        return;
    }
    v = o->q10;
    ((f32 *)&v)[3] = 2.0f;
    if (func_0040D0C0(&v, 100.0f) == -1) {
        return;
    }
    if (o->b20 != 6) {
        func_00311AF8(o);
        func_00311D40(o);
        func_00311970(o);
    }
    func_00311F80(o);
    func_003123D8(o);
    func_00312A80(o);
}
