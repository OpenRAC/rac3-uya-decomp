#include "common.h"

extern void func_003ACD60(void *);
extern void func_003ACDE0(void *);
extern void func_00422428(void *, s32, s32);
extern void func_003ACC28(void *);

void func_003ACBA8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    if (v[0x3AB] == 0 && *(s32 *)(v + 0x380) != -1) {
        if (v[0x3AA] != 0) {
            func_003ACD60(m);
        } else {
            func_003ACDE0(m);
        }
        func_00422428(m, 19, -1);
    } else {
        func_003ACC28(m);
    }
}
