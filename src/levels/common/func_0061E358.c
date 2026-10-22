#include "common.h"

/* localdecomp:start func_0061E358 */
extern s32 func_0065FDF0(u8 *, s32);
extern void *func_0065FCD0(u8 *, s32, s32, s32);
extern void func_006601C8(void *, void *, s32);

void func_0061E358(u8 *s, s32 a, s32 kind, s32 b) {
    u8 buf[16];
    void *p;

    if (s[0x1A14] != 0) {
        if (kind != 0) {
            if (func_0065FDF0(s, 8) == 0) {
                p = func_0065FCD0(s, 8, 0, 0);
                buf[0] = a;
                func_006601C8(p, buf, 1);
                buf[0] = b;
                func_006601C8(p, buf, 1);
            }
        } else {
            if (func_0065FDF0(s, 6) == 0) {
                p = func_0065FCD0(s, 6, 0, 0);
                buf[0] = a;
                func_006601C8(p, buf, 1);
                buf[0] = b;
                func_006601C8(p, buf, 1);
            }
        }
    }
}
/* localdecomp:end func_0061E358 */
