#include "common.h"

/* localdecomp:start func_00512248 */
extern void func_00512248();

extern f32 D_001E7600[];
extern f32 D_001E1668;
extern s32 D_001E166C;
extern s32 D_001D55E8;
extern void func_003FFAC8();
extern void func_004C1FE8(s32, unsigned long);
void func_00512248(void) {
    D_001E1668 = D_001E7600[0xB0/4];
    D_001E7600[0xB0/4] = 0.62f;
    func_003FFAC8();
    func_004C1FE8(0x47, 0x33001);
    D_001E166C = D_001D55E8;
}
/* localdecomp:end func_00512248 */
