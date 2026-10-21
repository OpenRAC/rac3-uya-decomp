#include "common.h"

/* localdecomp:start func_004DF380 */
extern f32 D_001DF9D0[];
extern s32 D_001DBD60[1];
extern s32 D_001DBD58[1];
extern f32 D_001DBD50[1];
extern f32 func_004450C0(f32 *, f32, f32);
void func_004DF380(void) {
    s32 i;
    f32 *a;
    s32 *st;
    s32 *en;
    f32 *pr;
    a = D_001DF9D0;
    st = D_001DBD60;
    en = D_001DBD58;
    pr = D_001DBD50;
    for (i = 0; i < 1; i++) {
        if (en[i] != 0) {
            if (st[i] == 0) {
                func_004450C0(&a[i], 1.0f, pr[i]);
                if (a[i] == 1.0f) {
                    st[i] = 1;
                }
            } else if (st[i] == 1) {
                st[i] = 2;
            } else if (st[i] == 2) {
                func_004450C0(&a[i], 0.0f, pr[i]);
                if (a[i] == 0.0f) {
                    en[i] = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_004DF380 */
