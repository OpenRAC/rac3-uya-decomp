#include "common.h"

extern s32 func_0041D298();

typedef struct { s16 f0; u8 b2; u8 p3[9]; s32 fC; } O_391B70;
typedef struct { u16 h0; u16 h2; u16 h4; u8 b6; u8 b7; } E_391B70;
extern u8 *D_001DFD9C_00391B70;
extern s32 D_001DFBC0_00391B70;
extern s32 func_00440848(s32, s32);
s32 func_0041D298(O_391B70 *o) {
    E_391B70 *e = (E_391B70 *)(D_001DFD9C_00391B70 + o->f0 * 8);
    s32 r = 0;
    if (e->h0 != 0xFFFF) {
        switch (o->b2) {
        case 0:
            r = e->h4;
            break;
        case 1:
            r = e->h4 + ((D_001DFBC0_00391B70 - o->fC) / e->b7) % e->h2;
            break;
        case 2: {
            s32 n = e->h2 * 2;
            r = ((D_001DFBC0_00391B70 - o->fC) / e->b7) % (n - 2);
            if (r >= e->h2) {
                s32 u = r + 2;
                r = n - u;
            }
            goto add;
        }
        case 3: {
            s32 t = o->fC;
            do {
                if (t < D_001DFBC0_00391B70) {
                    s32 n;
                    r = (D_001DFBC0_00391B70 - t) / e->b7;
                    n = e->h2 * 2;
                    if (r < n - 2) {
                        if (r >= e->h2) {
                            s32 u = r + 2;
                            r = n - u;
                        }
                    add:
                        r += e->h4;
                    } else {
                        s32 k;
                        r = e->h4;
                        k = func_00440848(0x1E, t) + 10;
                        o->fC = e->h2 * 2 + k;
                    }
                } else {
                    r = *(s32 *)((u8 *)o + 4);
                }
            } while (0);
        }
        }
    }
    *(s32 *)((u8 *)o + 4) = r;
    return r;
}
