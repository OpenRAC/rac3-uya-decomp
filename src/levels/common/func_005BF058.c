#include "common.h"

typedef struct {
    u8 data[36];
} Entry36;

extern s16 D_002724B0[];
extern u8 D_002723C0[];
extern u8 D_00274890[];
extern Entry36 D_004B2720[];

Entry36 *func_005BF058(u8 *a0) {
    u8 i = a0[34];
    if (D_002724B0[i] != *(s16 *)(a0 + 170)) {
        return &D_004B2720[D_00274890[i]];
    }
    return &D_004B2720[D_002723C0[i]];
}
