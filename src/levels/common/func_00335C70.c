#include "common.h"

/* localdecomp:start func_00335C70 */
typedef void (*Fn_335C70)(u8 *);

extern u8 *D_001E009C;
extern Fn_335C70 *func_00438488(s32, s32, s32);
extern Fn_335C70 *func_00438468(s32, s32);
extern void func_00436220(u8 *);
extern void func_00441FB8(u8 *, s32, s32);

void func_00335C70(u8 *m, s32 flag) {
    u8 *v = *(u8 **)(m + 104);
    u8 *o = 0;
    Fn_335C70 *r;
    Fn_335C70 *t;
    s32 idx;

    r = func_00438488(*(s32 *)(v + 64), 4, 156);
    if (*(u8 **)(m + 184) != 0) {
        o = *(u8 **)(*(u8 **)(m + 184) + 104);
    }
    idx = *(s32 *)(v + 80);
    if (idx != -1) {
        r[1](D_001E009C + (idx << 8));
    }
    if (*(s32 *)(v + 48) != 0) {
        t = func_00438468(6625, 108);
        t[0](m);
        if (flag != 0) {
            t[1](m);
        }
    } else if (o == 0 || *(s16 *)(o + 140) == -1) {
        func_00436220(m);
    } else {
        *(s32 *)(v + 80) = -1;
        func_00441FB8(m, 4, -1);
    }
}
/* localdecomp:end func_00335C70 */
