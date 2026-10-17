#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x31 - 0x10];
    u8 unk31;
    char pad32[0x68 - 0x32];
    char *vars;
    char pad6C[0x6F - 0x6C];
    u8 state;
    char pad70[0x96 - 0x70];
    u16 timer;
} Moby;

extern char D_001E2140[];
extern void func_003F64B8(void *);
extern void func_00438F00(Moby *, void *, s32, s32, f32);
extern f32 func_003F6A68(void *, void *);
extern void func_0042EA48(Moby *);

void func_0035E6F0(Moby *m) {
    char *v = m->vars;

    func_003F64B8(v + 724);
    func_003F64B8(v + 728);
    if (m->timer < 0xFFFF) {
        m->timer++;
    }
    func_00438F00(m, v + 576, 1, 1, 2.5f);
    if (m->unk31 != 0 && func_003F6A68(D_001E2140, m->pos) < 1024.0f) {
        func_0042EA48(m);
        m->state = 30;
    }
}
