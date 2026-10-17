#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u128_t pos;
    u128_t dir;
    s32 f32;
    u8 *f36;
    s32 f40;
    s32 f44;
} Vars3B65B0;

extern u8 *D_001DF240[];
extern u8 *func_0042A030(s32, s32);

u8 *func_003B65B0(s32 a0, u128_t *pos, u128_t *dir, s32 a3, s32 unused, s32 a5) {
    u8 *m = func_0042A030(6890, 128);
    Vars3B65B0 *v;

    if (m != 0) {
        m[32] = 0;
        m[48] = 255;
        v = *(Vars3B65B0 **)(m + 104);
        *(u128_t *)(m + 16) = *pos;
        v->pos = *pos;
        v->dir = *dir;
        v->f44 = a5;
        v->f32 = a3;
        v->f36 = D_001DF240[0] + 120;
        v->f40 = a0;
    }
    return m;
}
