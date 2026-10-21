#include "common.h"

/* localdecomp:start func_003F1B98 */
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_002F7700[];
void func_003F1B98(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_002F7700[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_003F1B98 */
