#include "common.h"
extern void func_003ACED8(void);
extern void func_003AC248(u8 *);
void func_003AC290(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    *(s32 *)(p + 84) = 0;
    *(s32 *)(p + 80) = 0;
    func_003ACED8();
    func_003AC248(a0);
}
