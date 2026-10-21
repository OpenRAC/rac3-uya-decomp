#include "common.h"

/* localdecomp:start func_00325208 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xB0];
    s32 wB0;
    u8 padB4[0xBE - 0xB4];
    u8 bBE;
    u8 padBF[0x100 - 0xBF];
    s128 q100;
    s128 q110;
} S_325208m;

typedef struct S_325208o {
    u8 pad0[0x10];
    s128 q10;
    u8 pad20[0x28 - 0x20];
    struct S_325208o *next;
    u8 pad2C[0x68 - 0x2C];
    S_325208m *p68;
    u8 pad6C[0xF0 - 0x6C];
    s128 qF0;
} S_325208o;

typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x6C - 0x28];
    S_325208o *p6C;
} S_325208;

typedef struct {
    s32 w0;
    S_325208o *w4;
} S_325208n;

extern S_325208o *D_001E00A8;
extern s32 func_00438488(s32 a0, s32 a1, s32 a2);
extern s32 func_00447CA0(S_325208o *a0);
extern s32 func_00453210(s128 *a0, s32 a1);
extern S_325208n *func_00445F18(S_325208o *a0);
extern void func_00326F30(S_325208o *a0);

void func_00325208(s32 a0, S_325208 *a1) {
    S_325208o *o;
    S_325208m *m;

    a1->p6C = 0;
    if (func_00438488(500, 1, 28) == 0) {
        return;
    }
    for (o = D_001E00A8; o != 0; o = o->next) {
        if (func_00447CA0(o) == 0) {
            continue;
        }
        if (func_00453210(&o->q10, a1->w24) == 0) {
            continue;
        }
        m = o->p68;
        if (m->wB0 != 0) {
            continue;
        }
        func_00445F18(o)->w4 = a1->p6C;
        a1->p6C = o;
        m = o->p68;
        m->q100 = o->q10;
        m->q110 = o->qF0;
        m->wB0 = -2;
        m->bBE = 7;
        func_00326F30(o);
    }
}
/* localdecomp:end func_00325208 */
