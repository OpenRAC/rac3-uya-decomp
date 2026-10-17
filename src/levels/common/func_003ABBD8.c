#include "common.h"

extern void func_003AC310(void);
extern void func_0042F238(u8 *o, s32 a, s32 b);

s32 func_003ABBD8(u8 *a0) {
    u8 *v;
    if (*(s16 *)(a0 + 170) != 6880) {
        return 0;
    }
    v = *(u8 **)(a0 + 104);
    if (*(s32 *)(v + 80) >= v[*(s32 *)(v + 44) * 32 + 522]) {
        return 0;
    }
    func_003AC310();
    func_0042F238(a0, 7, -1);
    return 1;
}
