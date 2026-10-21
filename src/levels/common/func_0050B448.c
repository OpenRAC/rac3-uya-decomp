#include "common.h"

/* localdecomp:start func_0050B448 */
typedef struct {
    s16 h;
    u8 b;
    u8 pad;
} E_0050B448;
extern E_0050B448 D_001DBE18;
extern E_0050B448 D_001DBE00;
extern E_0050B448 D_001DBE30;
extern s32 func_004E5470(s32);
s32 func_0050B448(s32 a0, s32 *a1) {
    E_0050B448 *p;
    p = 0;
    if (func_004E5470(3) == 2) {
        p = &D_001DBE18;
    } else if (func_004E5470(3) == 3) {
        p = &D_001DBE00;
    } else if (func_004E5470(3) == 4) {
        p = &D_001DBE30;
    }
    if (p != 0) {
        s32 i = 0;
        while (p[i].h != -1) {
            if (a0 == p[i].b) {
                *a1 = p[i].h;
                return 1;
            }
            i++;
        }
    }
    *a1 = 0;
    return 0;
}
/* localdecomp:end func_0050B448 */
