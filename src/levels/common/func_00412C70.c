#include "common.h"

/* localdecomp:start func_00412C70 */
extern void func_00412C70(s32, long, long);

extern unsigned long D_001D07E8[];
void func_00412C70(s32 arg0, long arg1, long arg2) {
    D_001D07E8[0] = arg0 | (arg1 << 8) | (arg2 << 0x10) | (unsigned long)0x80000000;
}
/* localdecomp:end func_00412C70 */
