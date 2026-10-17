#include "common.h"

typedef int q128 __attribute__((mode(TI)));

typedef struct {
    char pad0[0x150];
    q128 unk150;
    char pad160[0x190 - 0x160];
    q128 unk190;
    char pad1A0[0x300 - 0x1A0];
    q128 unk300;
    char pad310[0x940 - 0x310];
    q128 unk940;
} Vars;

typedef struct {
    char pad0[0x10];
    q128 pos;
    char pad20[0x34 - 0x20];
    u16 flags;
    char pad36[0x68 - 0x36];
    Vars *vars;
    char pad6C[0xA8 - 0x6C];
    u8 unkA8;
    char padA9[0xAA - 0xA9];
    s16 oClass;
} Moby;

extern void func_0042F238(Moby *, s32, s32);

void func_0034A318(void *arg0, Moby *m) {
    if (arg0 == 0 || m == 0) {
        return;
    }
    if (m->oClass == 7003) {
        m->pos = m->vars->unk940;
    }
    if (m->oClass == 7062) {
        m->pos = m->vars->unk150;
    }
    if (m->oClass == 7063) {
        m->pos = m->vars->unk300;
    }
    if (m->oClass == 7066) {
        m->pos = m->vars->unk190;
    }
    m->unkA8 = 255;
    m->flags &= ~2;
    func_0042F238(m, 0, -1);
}
