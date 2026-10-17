#include "common.h"

typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
extern E_38ED00 *D_001DFD9C[];
s32 func_00419888(s32);
extern s32 func_0041D880();

typedef struct { s16 a; s16 b; } P_392108;
typedef struct { s32 w; s32 pad; } W_392108;
extern u8 D_001D6A05;
extern P_392108 *D_001DFDA0[];
extern W_392108 *D_001DFDA4[];
extern W_392108 *D_001DFDA8[];
s32 func_0041D880(s32 key, s32 n) {
    s32 r;
    s32 idx;
    u32 mask;
    E_38ED00 *e;
    P_392108 *p;
    if (D_001D6A05 == 0) {
        r = func_00419888(key);
        D_001D6A05 = (u32)r >> 31;
        e = (E_38ED00 *)((r << 3) + (s32)D_001DFD9C[0]);
        if (e->x0 != 0xFFFF && n < e->x2) {
            idx = e->x4 + n;
            p = (P_392108 *)((idx << 2) + (s32)D_001DFDA0[0]);
            if ((D_001DFDA8[0][p->a].w & 0x80000000) == 0) {
                return (D_001DFDA4[0][p->b].w & 0x80000000) ? 0 : idx;
            }
        }
    }
    return 0;
}
