#include "common.h"

/* localdecomp:start func_004C5178 */
extern u8 *D_001E1AA4[];
extern s32 D_001DD69C;
extern void func_00436220(u8 *);
extern void func_00421FE0(s32);
void func_004C5178(void) {
    u8 **p = D_001E1AA4;
    s32 i;
    for (i = 8; i >= 0; i--) {
        if (*p != 0 && (*p)[32] != 254 && (*p)[32] != 253) {
            func_00436220(*p);
            *p = 0;
        }
        p++;
    }
    if (D_001DD69C != -1) {
        func_00421FE0(D_001DD69C);
        D_001DD69C = -1;
    }
}
/* localdecomp:end func_004C5178 */
