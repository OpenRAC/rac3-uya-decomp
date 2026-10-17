#include "common.h"

typedef struct { u8 p0[0xAA]; s16 hAA; u8 pad[0x100 - 0xAC]; } M_403828;
extern M_403828 *D_001DF21C;
extern M_403828 *D_001DF224;

M_403828 *func_00403828(s32 id) {
    M_403828 *p;
    for (p = D_001DF21C; p < D_001DF224; p++) {
        if (p->hAA == id) return p;
    }
    return 0;
}
