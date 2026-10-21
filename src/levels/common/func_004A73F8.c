#include "common.h"

/* localdecomp:start func_004A73F8 */
typedef struct { u8 b[128]; } E_1A30B0;
typedef struct { u8 b[32]; } B_001DFBEC;
extern B_001DFBEC *D_001DFBEC;
extern s32 D_001D669C;
extern s32 D_001DFBE8;
extern E_1A30B0 D_1A30B0[];
extern s32 func_004A6F58(void *, s32, s32, s32, s32);
s32 func_004A73F8(s32 a, s32 b, s32 c, s32 d) {
    s32 r;
    if (D_001DFBEC == 0) {
        return -1;
    }
    a += D_001D669C;
    if (a >= D_001DFBE8) {
        return -1;
    }
    r = func_004A6F58(&D_001DFBEC[a], b, c, 0, 0x400);
    if (r >= 0) {
        u8 *e = D_1A30B0[r].b;
        *(s32 *)(e + 0xDC) = c;
        *(s16 *)(e + 0xCA) = a;
        *(s32 *)(e + 0x114) = d;
    }
    return r;
}
/* localdecomp:end func_004A73F8 */
