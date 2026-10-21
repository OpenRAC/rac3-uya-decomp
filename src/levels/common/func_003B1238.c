#include "common.h"

/* localdecomp:start func_003B1238 */
extern u8 *D_001E009C;
extern s32 func_003B1D50(u8 *);

s32 func_003B1238(u8 *obj)
{
    u8 *vars = *(u8 **)(obj + 104);
    u8 *m = D_001E009C + (*(s32 *)(vars + 24) << 8);
    s32 n = 0;

    while (m != 0 && *(s16 *)(m + 170) != 6628) {
        u8 *v = *(u8 **)(m + 104);

        n += func_003B1D50(m);
        m = D_001E009C + (*(s32 *)v << 8);
    }
    return n;
}
/* localdecomp:end func_003B1238 */
