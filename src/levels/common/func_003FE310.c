#include "common.h"

/* localdecomp:start func_003FE310 */
typedef struct { u8 pad[0x22]; s16 h22; s16 h24; } S_3FE310;
typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad20[0x28 - 0x20]; } E_3FE310;
typedef struct { E_3FE310 e[32]; s32 w500; } T_3FE310;
typedef struct { u16 a; u16 pa; u16 b; u16 pb; } L_3FE310;
extern S_3FE310 D_001E6540;
extern T_3FE310 D_001E68D0;
extern s32 func_003FE1F0(s32, u16 *, u16 *);
s32 func_003FE310(void) {
    S_3FE310 *p = &D_001E6540;
    E_3FE310 *t;
    L_3FE310 l;
    s32 *w;
    if (p->h22 == -1) {
        p->h22 = 0;
        p->h24 = 0;
        return 1;
    }
    t = D_001E68D0.e;
    w = &t->w1C;
    if (func_003FE1F0(*(s32 *)(p->h22 * 40 + (s32)w), &l.a, &l.b) != 0 && *(s32 *)(p->h22 * 40 + (s32)w) != 0) {
        p->h22 = l.a;
        p->h24 = l.b;
        return 1;
    }
    D_001E6540.h22++;
    D_001E6540.h24 = 0;
    return D_001E6540.h22 < D_001E68D0.w500;
}
/* localdecomp:end func_003FE310 */
