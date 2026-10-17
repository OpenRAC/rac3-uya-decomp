#include "common.h"
typedef struct {
    u8 pad[12];
    s32 idx;
    u8 pad2[40];
} Ent00328BE0;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001426E0[];
extern Ent00328BE0 D_002AEA90[];
s32 func_00328BE0(u8 *a0) {
    u8 *a1 = *(u8 **)(a0 + 104);
    s32 v = *(s32 *)(a1 + 8);
    s32 i;
    Ent00328BE0 *e;
    if (v != -1 && (D_001BBC40[v + D_001D545C * 16] & 0x80)) {
        return 1;
    }
    if (a1[83] == 255) {
        return 0;
    }
    e = &D_002AEA90[a1[83]];
    i = e->idx;
    if (i == 0) {
        return 0;
    }
    return D_001426E0[i] != 0;
}
