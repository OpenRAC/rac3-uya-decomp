#include "common.h"
extern u8 *func_006197C0(s32 a0);
void func_005B6280(u8 *a0) {
    u8 *p = func_006197C0(0);
    if (p) {
        u8 *q = *(u8 **)(p + 9508);
        if (q) {
            *(long *)(a0 + 56) = *(long *)(q + 56);
        }
    }
}
