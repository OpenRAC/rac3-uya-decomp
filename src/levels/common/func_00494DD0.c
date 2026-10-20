#include "common.h"
typedef struct { s32 a[45]; } S180_00494DD0;
extern s32 D_001E0C10;
extern S180_00494DD0 D_00236868[];
extern void func_00494C90(S180_00494DD0 *);
S180_00494DD0 *func_00494DD0(s32 i) {
    if (D_001E0C10 == 0) {
        S180_00494DD0 *p = D_00236868;
        s32 n = 3;
        do {
            func_00494C90(p);
            p++;
        } while (--n != -1);
        D_001E0C10 = 1;
    }
    return &D_00236868[i];
}
