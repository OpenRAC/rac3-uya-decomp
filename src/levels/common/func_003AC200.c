#include "common.h"
extern void func_003ACED8(u8 *);
void func_003AC200(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 n = *(s32 *)(p + 80) + 1;
    s32 m;
    *(s32 *)(p + 80) = n;
    m = p[*(s32 *)(p + 44) * 32 + 522];
    if (m < n) {
        *(s32 *)(p + 80) = m;
    }
    func_003ACED8(a0);
}
