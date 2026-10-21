#include "common.h"

/* localdecomp:start func_00490A20 */
typedef struct { s32 a[5]; } S20_00490A20;
extern s32 D_001E0B88;
extern S20_00490A20 D_00236818[];
extern void func_00490CC8(S20_00490A20 *);
S20_00490A20 *func_00490A20(s32 i) {
    if (D_001E0B88 == 0) {
        S20_00490A20 *p = D_00236818;
        s32 n = 3;
        do {
            func_00490CC8(p);
            p++;
        } while (--n != -1);
        D_001E0B88 = 1;
    }
    return &D_00236818[i];
}
/* localdecomp:end func_00490A20 */
