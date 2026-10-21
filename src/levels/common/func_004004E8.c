#include "common.h"

/* localdecomp:start func_004004E8 */
extern void func_004C1FE8(s32, unsigned long);

extern void func_00412E30(s32, s32, s32, s32);
extern void func_004C1FE8(s32, unsigned long);
extern void func_00413258(s32, s32);
void func_004004E8(s32 a0, s32 a1) {
    s32 n = a0 + a1;
    if (n > 16) {
        n = 16;
    }
    func_00412E30(a0, a1, ((0x3FF000 - (4 << n)) >> 13) << 13, 1);
    func_004C1FE8(0x47, 0x30000);
    func_004C1FE8(0x42, 0x8000000044);
    func_00413258(0x100, 0x100);
    func_004C1FE8(0x42, 0x8000000044);
}
/* localdecomp:end func_004004E8 */
