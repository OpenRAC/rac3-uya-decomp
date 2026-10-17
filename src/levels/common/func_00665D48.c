#include "common.h"
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D48;
extern s32 D_001DAAE8;
extern E_665D48 D_00337800[];
E_665D48 *func_00665D48(s32 a0) {
    s32 i;
    E_665D48 *p;
    for (i = 0; i < D_001DAAE8; i++) {
        p = &D_00337800[i];
        if (p->w2D0 == a0) return p;
    }
    return 0;
}
