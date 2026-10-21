#include "common.h"

/* localdecomp:start func_00510C38 */
extern s32 func_00511368();
extern s32 func_005121D8();

extern s32 D_001DC160[];
extern s32 func_00511368();
extern s32 func_005121D8();
extern void func_005121C8();
s32 func_00510C38(s32 *a0, u32 a1, s32 a2) {
    s32 *p;
    s32 *obj;
    s32 *s1;
    if (a1 < 0x23) {
        if (*(s32 *)(a1 * 4 + *a0 + 0x50) == 0) {
            obj = (s32 *)func_00511368(a0, a2);
            if (obj != 0 && ((s32 (*)())(*(s32 *)(obj[2] + 0x10)))(obj, D_001DC160[0]) != 0) s1 = obj; else s1 = 0;
            if (s1 != 0) {
                p = (s32 *)(a1 * 4 + *a0); p += 0x14;
                if (*p != 0) func_005121D8(*p);
                *p = (s32)s1;
                func_005121C8(s1);
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_00510C38 */
