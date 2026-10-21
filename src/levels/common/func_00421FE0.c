#include "common.h"

/* localdecomp:start func_00421FE0 */
extern u8 D_001F1BC0[];
extern u8 D_001F1CC0[];
extern void func_00422328(void);
extern void func_0040BBD0(void *p, s32 n);

void func_00421FE0(u32 i)
{
    if (i < 8) {
        func_00422328();
        func_0040BBD0(D_001F1BC0 + i * 32, 32);
        func_0040BBD0(D_001F1CC0 + i * 48, 48);
    }
}
/* localdecomp:end func_00421FE0 */
