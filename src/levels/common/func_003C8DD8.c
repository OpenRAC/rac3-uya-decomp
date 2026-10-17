#include "common.h"

extern void func_00436220(s32);
extern void func_0044B7F0(u8 *, u8 *);
extern void func_00441FB8(u8 *, s32, s32);
extern void func_00335B98(u8 *);

void func_003C8DD8(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    if (*(s32 *)(s0 + 1360) != 0) {
        func_00436220(*(s32 *)(s0 + 1360));
        *(s32 *)(s0 + 1360) = 0;
    }
    func_0044B7F0(a0, s0 + 1232);
    func_00441FB8(a0, 1, -1);
    func_00335B98(a0);
}
