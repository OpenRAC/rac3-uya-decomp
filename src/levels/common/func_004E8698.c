#include "common.h"

/* localdecomp:start func_004E8698 */
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x64 - 0x21];
    void (*fn64)(void);
} S_4E8698o;

typedef struct {
    u8 pad0[0x1200];
    S_4E8698o *p0;
    S_4E8698o *p4;
    u8 pad8[0x14 - 0x8];
    s32 w14;
    u8 pad18[0x24 - 0x18];
    s32 w24;
    s32 w28;
} S_4E8698e;

extern u8 D_001A4BE0[];
extern void func_00436220(S_4E8698o *a0);

void func_004E8698(s32 idx, s32 a1) {
    S_4E8698e *t;
    S_4E8698e *e;
    S_4E8698o *o;

    t = (S_4E8698e *)(D_001A4BE0 + idx * 80);
    t->w14 = a1;
    if (t->w24 != 3) {
        o = t->p0;
        t->w24 = 3;
        if (o != 0 && o->b20 != 254 && o->b20 != 253 && o->fn64 != 0) {
            o->fn64();
        }
    }
    e = (S_4E8698e *)(D_001A4BE0 + idx * 80);
    e->w24 = 0;
    e->w28 = 0;
    if (e->p0 != 0) {
        func_00436220(e->p0);
        e->p0 = 0;
    }
    if (e->p4 != 0 && idx != 3) {
        func_00436220(e->p4);
        e->p4 = 0;
    }
}
/* localdecomp:end func_004E8698 */
