#include "common.h"

extern void func_003C6B80(u8 *, u8 *);
extern void func_003C7060(u8 *, u8 *);
extern void func_004C1FE8(s32, unsigned long);

void func_003C74E0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);

    func_003C6B80(a0, s);
    func_003C7060(a0, s);
    func_004C1FE8(8, 0);
    func_004C1FE8(71, 0x5360B);
}
