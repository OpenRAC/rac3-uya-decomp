#include "common.h"

/* localdecomp:start func_003C43E0 */
extern void func_003F3CE0(u8 *);
void func_003C43E0(s32 a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 84);
    if (s != 0 && *(s32 *)(s + 152) == 0) {
        func_003F3CE0(s);
        *(s32 *)(s + 152) = *(s32 *)(*(u8 **)(s + 36) + 16);
    }
}
/* localdecomp:end func_003C43E0 */
