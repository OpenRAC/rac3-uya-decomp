#include "common.h"

typedef struct {
    u8 p0[0x30];
    u8 v30[0x0E];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x160 - 0x60];
    u8 v160[0x304 - 0x160];
    s32 i304;
    f32 f308;
} S_Vars3A1638;

typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; S_Vars3A1638 *vars;
} S_Moby3A1638;

extern s32 func_003A1780(S_Moby3A1638 *);
extern s32 func_004329F0(S_Moby3A1638 *, void *, s32, s32, s32);
extern void func_003A1E90(S_Moby3A1638 *);
extern s32 func_00432338(S_Moby3A1638 *, void *, s32);
extern void func_003A1A58(S_Moby3A1638 *);
extern void func_00436600(S_Moby3A1638 *, s32);
extern void func_004366C8(S_Moby3A1638 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_003A1638(S_Moby3A1638 *m) {
    S_Vars3A1638 *v = m->vars;

    if (m->state == 0) {
        if (func_003A1780(m) != 0) {
            return 1;
        }
    }
    if (v->b3E == 2) goto special;
    if (func_004329F0(m, v->v160, 0, 0, 0) != 0) {
        func_003A1E90(m);
    }
    func_00432338(m, v->v30, 0);
    if (v->b5E != 0) {
special:
        func_003A1A58(m);
        return 1;
    }
    if (v->b5F != 0) {
        func_00436600(m, 5);
        func_004366C8(m, v->i304, 0, 0, 0, 0, 3, 0, 0, 0, v->f308, 10.0f, 1.0f);
    } else {
        func_00436600(m, 3);
        func_004366C8(m, v->i304, 0, 0, 0, 0, 1, 0, 0, 0, v->f308, 10.0f, 1.0f);
    }
    return 0;
}
