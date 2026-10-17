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

extern char D_001E1700[];
extern void func_003F0638(void *);
extern void func_003F0668(void *);
extern void func_00431F40(Moby *, void *, s32, s32, f32);
extern f32 func_003F0BE8(void *, void *);
extern void func_00427790(Moby *);

void func_0034F0B8(Moby *m) {
    char *v = m->vars;

    func_003F0638(v + 2256);
    func_003F0668(v + 2260);
    if (m->timer < 0xFFFF) {
        m->timer++;
    }
    func_00431F40(m, v + 576, 10, 1, 2.5f);
    if (m->unk31 != 0 && func_003F0BE8(D_001E1700, m->pos) < 576.0f) {
        func_00427790(m);
        m->state = 22;
    }
}
