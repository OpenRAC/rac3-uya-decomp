#include "common.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[122];
    s32 f124;
    u8 pad2[4];
    u16 h132;
    u8 pad3[106];
} Ent_00416BF8;

extern u8 D_001425C0[];
extern Ent_00416BF8 D_002C5640[];
extern u8 D_00142CA0[];
/* Real table holds 32 slots; declared small so the address is one la. */
extern u16 D_001D54D8[4];

s32 func_00416BF8(s32 idx) {
    Ent_00416BF8 *e = &D_002C5640[D_001425C0[idx]];
    s32 r = 0;
    s32 i;
    u16 v;
    s32 f;

    if (e->b0 != 0 && e->b1 == 0 && (e->f124 != 0 || e->h132 != 0)) {
        for (i = 0; i < 32; i++) {
            v = D_001D54D8[i];
            if (((v & 0x3FFF) == idx && !(v & 0x4000)) || v == 0xFFFF) {
                f = D_00142CA0[idx] ? 0x8000 : 0;
                D_001D54D8[i] = idx | f;
                r = 1;
                break;
            }
        }
    }
    return r;
}
