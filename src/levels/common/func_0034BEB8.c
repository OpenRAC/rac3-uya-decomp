#include "common.h"

/* localdecomp:start func_0034BEB8 */
extern void func_00438908(void *, s32, s32, s32);

void func_0034BEB8(u8 *s) {
    u8 *m;

    func_00438908(*(u8 **)(s + 0x18), s[4], s[5], s[6]);
    m = *(u8 **)(s + 0x18);
    if (*(u16 *)(m + 0x34) & 0x20) {
        u8 *p = *(u8 **)(*(u8 **)(m + 0x68) + 0x10);
        if (p != 0 && *(s16 *)p != 0) {
            p[4] = s[4];
            p[5] = *(s32 *)(s + 4) >> 8;
            p[6] = *(s32 *)(s + 4) >> 16;
        }
    }
}
/* localdecomp:end func_0034BEB8 */
