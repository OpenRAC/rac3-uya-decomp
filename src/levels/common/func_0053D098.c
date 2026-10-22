#include "common.h"

/* localdecomp:start func_0053D098 */
extern u8 *D_00352C4C[];
extern u8 *D_0024C05C;
extern s32 func_0053D070(u8 *);
extern s32 func_0053D048(u8 *);

s32 func_0053D098(u8 *p) {
    u8 *g = D_00352C4C[0];
    u8 *e = 0;
    s32 t = 0x5A;
    s32 a;
    s32 b;

    if (*(s32 *)(g + 0x88) == *(s32 *)(p + 0x2548)) {
        e = D_0024C05C + (*(s32 *)(g + 0x40) << 8);
    } else if (*(s32 *)(g + 0x8C) == *(s32 *)(p + 0x2548)) {
        e = D_0024C05C + (*(s32 *)(g + 0x44) << 8);
    }
    if (e != 0) {
        a = func_0053D070(e);
        b = func_0053D048(e);
        if (b != 0) {
            t = 0xD2;
        }
        if (a != 0) {
            t += 0x78;
        }
        if (a != 0 && b != 0) {
            t += 0x78;
        }
    }
    return t;
}
/* localdecomp:end func_0053D098 */
