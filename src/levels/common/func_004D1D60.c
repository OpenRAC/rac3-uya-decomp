#include "common.h"

/* localdecomp:start func_004D1D60 */
extern s32 func_004D1D60();

extern void func_004CF0E8(void);
extern void func_004D0D00(u8 *);
extern u8 *D_001E1264[];
s32 func_004D1D60(void) {
    func_004CF0E8();
    func_004D0D00(D_001E1264[0] + 0x48);
    return 1;
}
/* localdecomp:end func_004D1D60 */
