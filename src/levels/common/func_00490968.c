#include "common.h"

/* localdecomp:start func_00490968 */
typedef struct { u8 b[32]; } E_00490968;
extern s32 D_001E0B70;
extern E_00490968 D_00236798[];
extern void func_00490AA8(E_00490968 *);
E_00490968 *func_00490968(s32 i) {
    s32 n;
    E_00490968 *p;
    if (D_001E0B70 == 0) {
        p = D_00236798;
        for (n = 3; n != -1; n--) {
            func_00490AA8(p);
            p++;
        }
        D_001E0B70 = 1;
    }
    return &D_00236798[i];
}
/* localdecomp:end func_00490968 */
