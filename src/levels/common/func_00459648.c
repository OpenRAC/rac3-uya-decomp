#include "common.h"

/* localdecomp:start func_00459648 */
typedef struct {
    u8 pad0[8];
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14[32];
    f32 f34;
    s32 w38;
    u8 pad3C[20];
    u8 v50[16];
    u8 pad60[48];
    f32 f90;
    s32 flags;
    u8 pad98[8];
    u8 vA0[16];
    u8 padB0[16];
    s16 hC0;
    s16 hC2;
    u8 padC4[8];
    f32 fCC;
    u8 padD0[8];
    s32 wD8;
} S_00459648;

typedef struct { f32 v[4]; } V_00459648;
extern V_00459648 D_001DFCD0;
extern V_00459648 D_001DFCD0_00459648;
extern void func_00459A98(u8 *, S_00459648 *);
extern f32 func_0040BFB0(void *, void *);
extern f32 func_0044DCE0(u8 *, void *, s32);
extern u8 *func_00445EB8(u8 *);
extern void func_004585E8(u8 *, S_00459648 *);
extern void func_0044DEA8(u8 *, void *, s32);
extern void func_0044DBC8(u8 *, void *, f32, f32, f32);
extern s32 func_00459E50(u8 *, S_00459648 *);
extern void func_00443A90(u8 *, s32, s32, void *, f32);

void func_00459648(u8 *obj, S_00459648 *b, void *target, s32 snap) {
    s32 changed;
    f32 d;
    u8 *p;

    changed = 0;
    func_00459A98(obj, b);
    d = func_0040BFB0(obj + 16, &D_001DFCD0);
    if (d < b->f90 - b->f8) {
        b->flags |= 2;
        changed = 1;
    }
    if (((((u8 *)b)[56] ^ 1) & 1) && b->hC2 < 5 && b->f90 + b->fC < d) {
        b->flags |= 1;
        changed = 1;
    }
    if (b->hC0 != 0 && b->f10 < func_0044DCE0(obj, b->v50, 0)) {
        b->flags |= 4;
        changed = 1;
    }
    if (b->wD8 != -1 && b->hC0 != 0) {
        p = func_00445EB8(obj);
        if (p != 0 && p[73] != 0 && *(u16 *)(p + 74) != 0 && ((*(u16 *)(p + 74) >> b->wD8) & 1)) {
            b->flags |= 0x200;
            changed = 1;
        }
    }
    if (changed) {
        func_004585E8(obj, b);
        func_00459A98(obj, b);
        d = func_0040BFB0(obj + 16, &D_001DFCD0_00459648);
    }
    if (d <= b->f90 + 0.005f) {
        func_0044DEA8(obj, b->vA0, 0);
        if (snap) {
            func_0044DBC8(obj, obj + 16, 0.0f, 0.0f, b->f90 - d);
        }
        b->hC2 = 0;
        b->hC0++;
    } else if (b->f90 + b->fC <= d) {
        b->hC0 = 0;
        b->hC2++;
    }
    b->fCC = func_0040BFB0(obj + 16, target);
    if (b->fCC <= b->f34) {
        b->flags |= 0x80;
    }
    if ((b->w38 & 0x200) && func_00459E50(obj, b)) {
        func_00443A90(obj, 0, 0x10000, obj + 16, 255.0f);
    }
}
/* localdecomp:end func_00459648 */
