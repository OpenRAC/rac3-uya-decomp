#include "common.h"
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D00;
extern s32 D_001DAAE8;
extern E_665D00 D_00337800[];
E_665D00 *func_00665D00(s32 a0) {
    s32 i;
    for (i = 0; i < D_001DAAE8; i++) {
        if (D_00337800[i].id == a0) return &D_00337800[i];
    }
    return 0;
}
