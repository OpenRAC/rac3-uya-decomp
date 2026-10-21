#include "common.h"

/* localdecomp:start func_0066A020 */
extern s32 *D_001DAC20;
extern s32 func_0061AC78(s32, s32);
extern void *func_0065FCD0(s32 *, s32, s32, s32);
extern void func_006601C8(void *, void *, s32);

s32 func_0066A020(s32 a, void **out, u32 *opt) {
    u32 buf[3];
    u32 w = 0xFFFFFFFF;
    s32 id = func_0061AC78(7, -1);
    void *p = func_0065FCD0(D_001DAC20, 0, 0, 0xFA);

    if (opt != 0) {
        w = *opt;
    }
    buf[0] = id;
    func_006601C8(p, &buf[0], 4);
    buf[1] = a;
    func_006601C8(p, &buf[1], 4);
    buf[2] = w;
    func_006601C8(p, &buf[2], 4);
    if (out != 0) {
        *out = p;
    }
    return id;
}
/* localdecomp:end func_0066A020 */
