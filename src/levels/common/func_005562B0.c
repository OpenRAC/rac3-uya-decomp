#include "common.h"

/* localdecomp:start func_005562B0 */
extern s32 D_0024D648[15];
extern s32 D_0024D688;
extern s32 D_001E1DF8;
extern s32 func_00556230();
extern s32 func_005B2498(s32);
extern void func_00555C28(s32, s32, s32);
extern void func_00556268(s32);

void func_005562B0(s32 x) {
    s32 i;
    s32 n;
    s32 *s;

    if (func_00556230() == 0) {
        for (i = 0; i < 16; i++) {
            if (D_0024D648[i] == 0) {
                D_0024D648[i] = x;
                return;
            }
        }
        n = D_001E1DF8;
    } else {
        s = &D_0024D648[func_005B2498(16)];
        func_00555C28(*s, 0, 0);
        func_00556268(*s);
        *s = x;
        n = D_0024D688;
    }
    D_0024D688 = n + 1;
}
/* localdecomp:end func_005562B0 */
