#include "common.h"

/* localdecomp:start func_004AD678 */
typedef struct {
    u8 *base;
    s32 count;
    s32 pad[2];
} E_004AD678;
extern E_004AD678 D_0023B360[];
extern s32 D_001D4B08;
extern s32 func_004AD788(u32);
extern s32 func_00122810(void *, s32, s32, u8 **, s32, u8 *, s32, s32, s32);
s32 func_004AD678(u8 *buf, u32 idx, s32 start, s32 n, s32 arg) {
    u8 *dst;
    s32 c;
    s32 sz;
    if (n == -1) {
        n = func_004AD788(idx);
    }
    if (idx >= 64 || D_0023B360[idx].count == 0) {
        return -3;
    }
    if (D_0023B360[idx].count < start + n) {
        return -1;
    }
    dst = D_0023B360[idx].base + start * 16;
    while (n != 0) {
        c = n;
        if (c > 0xFFFF) {
            c = 0xFFFF;
        }
        sz = c * 16;
        func_00122810(&D_001D4B08, 1, arg, &dst, 16, buf, sz, 0, 0);
        n -= c;
        buf += sz;
        dst += sz;
    }
    return 0;
}
/* localdecomp:end func_004AD678 */
