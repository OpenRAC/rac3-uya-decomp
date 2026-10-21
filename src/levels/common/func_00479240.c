#include "common.h"

/* localdecomp:start func_00479240 */
extern void func_00479240(void *, s32);

typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;
extern S_003ADCB0 D_00142430;
extern u8 D_001D4BE0;
extern u8 D_001D4BE0_b_003ADCB0;
extern void func_0012BE28();
extern void func_0013AD58();
extern void func_00432680();
void func_00479240(void *a, s32 b) {
    S_003ADCB0 *e = &D_00142430;
    func_0012BE28(&D_001D4BE0);
    func_0013AD58(&D_001D4BE0_b_003ADCB0);
    func_00432680(a);
    e->f174 = (s32)a;
    e->h18 = b;
    e->f148 = 0;
    if (e->f164 < 0) {
        e->f168 = 0;
        e->f164 = 0x13;
    }
}
/* localdecomp:end func_00479240 */
