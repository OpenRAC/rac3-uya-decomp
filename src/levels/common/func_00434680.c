#include "common.h"

/* localdecomp:start func_00434680 */
typedef struct { u8 p0[0x8]; s16 h8; s16 hA; s32 fC; s16 h10; u8 p1[2]; s32 f14; u16 f18; u8 p2[0xA]; s32 (*f24)(s32); s32 f28; s16 f2c; s16 f2e; } E_434680;
extern E_434680 *D_002E9A30[];
extern E_434680 *D_001DFFB8;
extern s32 D_001DFFB4;
extern u8 D_001D5570[8];
extern s32 func_004348C0(s32, s32, s32);
extern void func_00434490();
extern void func_00434550(s32, s32);
extern s32 func_00434640(u32);
static __inline__ u8 isEnd_434680(E_434680 *e) {
    s32 r = 1;
    if (e != 0 && e->h8 != 0) r = 0;
    return r;
}
s32 func_00434680(u32 i) {
    E_434680 *e, *f, *g;
    s32 j;
    s32 r;
    if (i >= 0x3C) return 0;
    if (D_002E9A30[i] == 0) return 0;
    func_00434640(i);
    if (D_001DFFB8 == 0) return 0;
    for (j = 0; isEnd_434680(e = (E_434680 *)(j * 48 + (s32)D_002E9A30[i])) == 0; j++) {
        if ((e->f18 & 4) && D_001D5570[i] == 0) {
            e->f2c = 0;
            continue;
        }
        if (func_004348C0(i, e->hA, e->fC) == 0) {
            if (e->f2c != 0) func_00434490();
            e->f2c = 0;
            continue;
        }
        if (func_004348C0(i, e->h10, e->f14) == 0) {
            if (e->f2c != 1) {
                e->f2c = 1;
                func_00434550(i, j);
                func_00434490();
            }
            continue;
        }
        if (e->f2c != 2) {
            func_00434490();
            e->f2c = 2;
            func_00434550(i, j);
        }
    }
    for (j = 0; isEnd_434680(f = (E_434680 *)(j * 48 + (s32)D_001DFFB8)) == 0; j++) {
        if (f->f24 != 0) {
            r = f->f24(f->f28);
            D_001DFFB8[j].f2e = r;
        }
    }
    D_001DFFB4 = 0;
    for (g = D_001DFFB8; isEnd_434680(g) == 0; g++) {
        if (g->f2c == 1 && !(g->f18 & 2)) D_001DFFB4++;
    }
    return *(volatile s32 *)&D_001DFFB4 == 0;
}
/* localdecomp:end func_00434680 */
