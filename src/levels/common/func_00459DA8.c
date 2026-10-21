#include "common.h"

/* localdecomp:start func_00459DA8 */
extern u8 *D_0021F740[];
extern u8 *func_00458650(u8 *);
extern s32 func_004432C0(u8 *, u8 *, s32);
extern s32 func_004736B8(s32, f32, u8 *, f32 *);

s32 func_00459DA8(u8 *a) {
    u8 *o;
    u8 *e;
    u8 *p;
    f32 buf[4];

    o = func_00458650(a);
    if (o == 0 || *(s32 *)(o + 60) == -1) {
        return 0;
    }
    e = D_0021F740[*(s32 *)(o + 60)];
    p = a + 16;
    if (func_004432C0(p, e + 16, *(s32 *)e) != 0) {
        if (func_004736B8(*(s32 *)(o + 60), *(f32 *)o, p, buf) == 0) {
            return 1;
        }
    }
    *(s32 *)(o + 156) |= 1;
    return 0;
}
/* localdecomp:end func_00459DA8 */
