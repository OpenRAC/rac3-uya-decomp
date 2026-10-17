#include "common.h"

typedef struct {
    void (*fn0)(void *);
} Iface;

typedef struct {
    char pad0[0x30];
    f32 unk30;
    char pad34[0x80 - 0x34];
    s32 unk80;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
    char pad6C[0x96 - 0x6C];
    s16 unk96;
} Moby;

extern Moby *D_001A65C0[];
extern s32 D_001D545C;
extern void func_00350468(Moby *);
extern void func_00402F60(s32, s32);
extern Iface *func_0044A528(s32, s32);

void func_00353590(Moby *m, s32 arg1) {
    Vars *v = m->vars;

    if (D_001A65C0[0] == m) {
        if (v->unk30 > 0.0f || D_001D545C == 20) {
            func_00350468(m);
        }
        func_00402F60(28, 0);
    }
    if (v->unk80 != 0) {
        if (arg1 == 0) {
            func_0044A528(6625, 108)->fn0(m);
        }
    } else {
        m->unk96 = 0;
    }
}
