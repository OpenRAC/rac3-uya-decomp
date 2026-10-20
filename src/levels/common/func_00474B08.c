#include "common.h"
extern s32 D_001E036C;
extern s32 D_001E0358;
extern void func_00510878(s32 *);
s32 *func_00474B08(s32 i) {
    s32 n;
    s32 *p;
    if (D_001E036C == 0) {
        p = &D_001E0358;
        for (n = 4; n != -1; n--) {
            func_00510878(p);
            p++;
        }
        D_001E036C = 1;
    }
    return &(&D_001E0358)[i];
}
