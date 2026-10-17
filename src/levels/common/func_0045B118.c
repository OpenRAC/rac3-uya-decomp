#include "common.h"

typedef struct {
    u8 data[36];
} Ent45B118;

extern u8 D_001FDC50[];
extern s16 D_001FDA70[];
extern u8 D_001FD980[];
extern u8 D_001FFE50[];
extern Ent45B118 D_002F73B4[];

Ent45B118 *func_0045B118(s32 id) {
    u8 idx = D_001FDC50[id];
    if (idx == 255) {
        return 0;
    }
    if (D_001FDA70[idx] != id) {
        return &D_002F73B4[D_001FFE50[idx]];
    }
    return &D_002F73B4[D_001FD980[idx]];
}
