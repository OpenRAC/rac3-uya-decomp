#include "common.h"

/* localdecomp:start func_00402B90 */
extern s32 D_001DF9C8;
extern s32 D_001A1ED4[];
extern s32 D_001D4BC4;
extern void func_004C1E50(s32 a0);
extern s32 func_0012C908(s32 a0);
extern void func_004C1C68(void);
extern void func_004C23C8(s32 a0, s32 a1, s32 a2);
void func_00402B90(s32 a0) {
    func_004C1E50(1);
    func_0012C908(0);
    D_001DF9C8++;
    func_004C1C68();
    func_004C23C8(a0, D_001A1ED4[0], D_001D4BC4 << 11);
}
/* localdecomp:end func_00402B90 */
