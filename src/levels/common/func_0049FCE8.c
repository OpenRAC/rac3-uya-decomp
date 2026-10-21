#include "common.h"

/* localdecomp:start func_0049FCE8 */
extern u8 D_001E7600[];
extern u8 *D_001E009C[];
extern u8 *D_001E00A4[];
extern void func_00457360(s32, s32);
extern void func_00412C70(s32, s32, s32);

void func_0049FCE8(void) {
    u8 *p;
    u8 *end;
    func_00457360(0, 0);
    p = D_001E7600;
    func_00412C70(*(s32 *)(p + 604), *(s32 *)(p + 608), *(s32 *)(p + 612));
    end = D_001E00A4[0];
    for (p = D_001E009C[0]; p < end; p += 256) {
        *(u16 *)(p + 52) &= ~0x80;
    }
}
/* localdecomp:end func_0049FCE8 */
