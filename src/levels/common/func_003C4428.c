#include "common.h"

/* localdecomp:start func_003C4428 */
extern void func_003F3D38(u8 *);

void func_003C4428(void *self, u8 *obj) {
    u8 *s = *(u8 **)(obj + 84);
    if (s != 0 && *(s32 *)(s + 152) != 0) {
        func_003F3D38(s);
        *(s32 *)(s + 152) = 0;
    }
}
/* localdecomp:end func_003C4428 */
