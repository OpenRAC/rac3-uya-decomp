#include "common.h"

/* localdecomp:start func_004DA100 */
extern s32 func_004D8DF0(s32 *, s32);
extern void func_004DA1B8(void);
extern void func_004DA8D0(void);
extern s32 D_001D5608, D_001D5610, D_001D5614, D_001D561C;
extern s32 D_001D5624, D_001D560C, D_001D5620, D_001D55EC;
extern s32 D_001A1ED4[];
void func_004DA100(void) {
    s32 p, r1, r2, r3;
    D_001D5608 = 0x3FA000;
    D_001D560C = 0x3FE000;
    D_001D5624 = 0x400000;
    p = 0x379000;
    r1 = func_004D8DF0(&p, 0x40000);
    p = 0x379000;
    D_001D5614 = r1;
    r2 = func_004D8DF0(&p, 0x40000);
    D_001D561C = r2;
    r3 = func_004D8DF0(&p, 0x40000);
    D_001D5620 = r3;
    D_001D5610 = D_001A1ED4[0];
    func_004DA1B8();
    func_004DA8D0();
    D_001D55EC = D_001D55EC | 1;
}
/* localdecomp:end func_004DA100 */
