#include "common.h"

typedef struct {
    u8 p0[0x464];
    u8 x464[1];
} T_3A1F48;

extern s32 func_00435F30(u8 *, s32);
extern s32 func_00435C80(u8 *);
extern f32 func_003EF288(void *a, void *b);
extern u8 *D_001DF21C;
extern s32 D_001D545C;
extern T_3A1F48 D_00235280;
extern u8 D_001BBE90[];

s32 func_003A1F48(u8 *moby, s32 alt) {
    u8 *pv = *(u8 **)(moby + 0x68);
    s32 a = alt ? *(s32 *)(pv + 0x2EC) : *(s32 *)(pv + 0x2D4);
    s32 b = alt ? *(s32 *)(pv + 0x2F4) : *(s32 *)(pv + 0x2DC);
    s32 c = alt ? *(s32 *)(pv + 0x2FC) : *(s32 *)(pv + 0x2E4);
    u8 *o;

    if (a != -1 && func_00435F30(pv + 0x220, a)) {
        return 1;
    }
    if (b != -1) {
        u16 h;
        s32 v;
        o = D_001DF21C + (b << 8);
        if (func_00435C80(o)) {
            return 1;
        }
        h = *(u16 *)(o + 0xB2);
        if (D_00235280.x464[(s16)h] || (v = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)], (h & 1) ? (v >> 4) & 7 : v & 7)) {
            if (func_003EF288(pv + 0x220, o + 0x10) < 49.0f) {
                return 1;
            }
        }
    }
    if (c != -1) {
        u8 *q = D_001DF21C + (c << 8);
        if (q == 0 || q[0x20] == 0xFE || q[0x20] == 0xFD) {
            if (alt) {
                *(s32 *)(pv + 0x2FC) = -1;
            } else {
                *(s32 *)(pv + 0x2E4) = -1;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
