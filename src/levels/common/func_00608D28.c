#include "common.h"
extern void func_00585398(void);
extern void func_00586D40(void);
extern void func_00608D78(void);
extern void func_00596FD0(void);
extern s32 D_001E03C8;
extern void (*D_001DA110)(void);
void func_00608D28(void) {
    func_00585398();
    func_00586D40();
    D_001E03C8 = -1;
    if (D_001DA110 != 0) {
        D_001DA110();
    }
    func_00608D78();
    func_00596FD0();
}
