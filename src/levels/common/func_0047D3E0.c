#include "common.h"

/* localdecomp:start func_0047D3E0 */
extern s32 D_001D841C;
extern u8 D_001D8438;
extern void func_00430120(s32, s32);

extern s32 D_001D841C;
extern u8 D_001D8438;
extern void func_00430120(s32, s32);
extern void func_004303A0(void);
void func_0047D3E0(void) {
    func_004303A0();
    if (D_001D841C != 0) {
        func_00430120(D_001D841C, 1);
        D_001D8438 = 1;
    }
}
/* localdecomp:end func_0047D3E0 */
