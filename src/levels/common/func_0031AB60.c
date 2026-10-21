#include "common.h"

/* localdecomp:start func_0031AB60 */
extern void func_00438908(u8 *, s32, s32, s32);

void func_0031AB60(u8 *s) {
    u8 *m;
    u8 *q;

    func_00438908(*(u8 **)(s + 20), s[4], s[5], s[6]);
    m = *(u8 **)(s + 20);
    if (*(u16 *)(m + 52) & 0x20) {
        q = *(u8 **)(*(u8 **)(m + 104) + 16);
        if (q != 0 && *(s16 *)q != 0) {
            q[4] = s[4];
            q[5] = *(s32 *)(s + 4) >> 8;
            q[6] = *(s32 *)(s + 4) >> 16;
        }
    }
}
/* localdecomp:end func_0031AB60 */
