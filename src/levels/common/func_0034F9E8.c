#include "common.h"
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad1[52 - 33];
    u16 flags;
    u8 pad2[104 - 54];
    void *vars;
} Moby_0034F9E8;
extern u8 D_001DD380[];
extern void func_0034FA90(Moby_0034F9E8 *, void *);
extern s32 func_00350F50(Moby_0034F9E8 *, void *);
extern s32 func_00490FC0(Moby_0034F9E8 *, void *);
extern void func_0034FEC0(Moby_0034F9E8 *, void *);
extern void func_00351BB8(Moby_0034F9E8 *, void *);
extern void func_00351DA0(Moby_0034F9E8 *, void *);
extern void func_00354048(Moby_0034F9E8 *, void *);
void func_0034F9E8(Moby_0034F9E8 *m) {
    void *v;
    if (m->flags & 2) return;
    v = m->vars;
    if (m->state == 0) func_0034FA90(m, v);
    if (func_00350F50(m, v) == 0) return;
    if (func_00490FC0(m, D_001DD380)) {
        func_0034FEC0(m, v);
        func_00351BB8(m, v);
        func_00351DA0(m, v);
        func_00354048(m, v);
    }
}
