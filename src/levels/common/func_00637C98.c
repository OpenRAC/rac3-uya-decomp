#include "common.h"
extern void func_005F0F68(s32, s32, s32, s32, s32, s32);
void func_00637C98(u8 *p, s32 a, s32 b, s32 en, s32 t) {
    s32 f;
    if (en) {
        f = 0;
        if (*(s32 *)(p + 0x4A0)) {
            f = *(s32 *)(p + 0x4C8) == 14;
        }
        t = (t << 10) / 30;
        func_005F0F68(a, b, f, 0, *(s32 *)(p + 0x2524), t);
    }
}
