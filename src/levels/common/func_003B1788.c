#include "common.h"

/* localdecomp:start func_003B1788 */
extern void func_003B1858(u8 *m, u8 *v);
extern s32 func_0040BA90(u8 *p);
extern s32 func_003B1EB0(u8 *m, u8 *v);
extern void func_003B29E8(u8 *m, u8 *v);
extern s32 func_003B2450(u8 *m, u8 *v);
extern void func_003B2A48(u8 *m, u8 *v);
extern void func_003B3580(u8 *m, u8 *v);

void func_003B1788(u8 *m) {
    u8 *v = *(u8 **)(m + 104);

    if (m[32] == 0) {
        func_003B1858(m, v);
    }
    switch (m[32]) {
    case 1:
        *(u16 *)(m + 52) |= 2;
        break;
    case 2:
        if (func_0040BA90(v + 44) != 0) {
            *(s32 *)(v + 44) = 6;
            if (func_003B1EB0(m, v) != 0) {
                func_003B29E8(m, v);
                break;
            }
            if (func_003B2450(m, v) != 0) {
                func_003B2A48(m, v);
                break;
            }
        }
        func_003B3580(m, v);
        break;
    }
}
/* localdecomp:end func_003B1788 */
