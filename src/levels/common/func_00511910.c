#include "common.h"

/* localdecomp:start func_00511910 */
typedef struct { s32 a[7]; } S28_00511910;
extern s32 D_001E1658;
extern s32 D_001E1620;
extern void func_0051DAC0(S28_00511910 *);
extern u8 func_00511878[];
extern void func_00116FD0(void (*)(void));
S28_00511910 *func_00511910(s32 i) {
    if (D_001E1658 == 0) {
        S28_00511910 *p = (S28_00511910 *)&D_001E1620;
        s32 n = 1;
        do {
            func_0051DAC0(p);
            p++;
        } while (--n != -1);
        D_001E1658 = 1;
        func_00116FD0((void (*)(void))(func_00511878 + 0x38));
    }
    return &((S28_00511910 *)&D_001E1620)[i];
}
/* localdecomp:end func_00511910 */
