#include "common.h"

/* localdecomp:start func_00528620 */
extern s32 D_0024D5A0[15];
extern s32 D_0024D5E0;
extern s32 D_001E1D50;
extern s32 func_005285A0();
extern s32 func_005B2498(s32);
extern void func_00528298(s32);
extern void func_005285D8(s32);

void func_00528620(s32 x) {
    s32 i;
    s32 n;
    s32 *s;

    if (func_005285A0() == 0) {
        for (i = 0; i < 16; i++) {
            if (D_0024D5A0[i] == 0) {
                D_0024D5A0[i] = x;
                return;
            }
        }
        n = D_001E1D50;
    } else {
        s = &D_0024D5A0[func_005B2498(16)];
        func_00528298(*s);
        func_005285D8(*s);
        *s = x;
        n = D_0024D5E0;
    }
    D_0024D5E0 = n + 1;
}
/* localdecomp:end func_00528620 */
