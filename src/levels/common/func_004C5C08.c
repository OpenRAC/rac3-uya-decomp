#include "common.h"

/* localdecomp:start func_004C5C08 */
extern u8 *D_001E02F8;
extern s32 D_001E0300;
extern void func_0045E580(u8 *);

void func_004C5C08(void) {
    s32 i;
    u8 *p;

    for (i = 0; i <= D_001E0300; i++) {
        p = D_001E02F8 + i * 64;
        if ((*(unsigned long *)p & 0x80FF) == 0xFF) {
            func_0045E580(p);
        }
    }
}
/* localdecomp:end func_004C5C08 */
