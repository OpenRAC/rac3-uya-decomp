#include "common.h"

/* localdecomp:start func_004797D0 */
extern s32 D_001D81F4;
extern void func_004799C0(void);
extern void func_004799C8();
extern void func_00479E38(void);
extern void func_0042FFD8();
extern void func_004795F8();

extern s32 D_001D81F4;
extern s32 D_001D8200;
extern void func_0042FFD8();
extern void func_004795F8();
extern void func_004796B0();
extern void func_004799C8(void);
extern void func_00479E38(void);
extern void func_004799C0(void);
void func_004797D0(void) {
    switch (D_001D81F4) {
    case 0:
        func_0042FFD8(func_004795F8, 0, func_004796B0);
        func_004799C8();
        D_001D8200 = 30;
        D_001D81F4++;
        break;
    case 1:
        func_004799C8();
        { s32 t = D_001D8200; if (t > 0) { t--; D_001D8200 = t; } D_001D8200 = t; if (t == 0) func_00479E38(); }
        break;
    case 2:
        func_004799C0();
        break;
    }
}
/* localdecomp:end func_004797D0 */
