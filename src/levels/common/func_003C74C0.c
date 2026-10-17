#include "common.h"

extern s32 D_00264F80[];
extern void func_003C7DF0(u8 *);
extern void func_003C8200();
extern void func_00455FC8(void *, u8 *);

void func_003C74C0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        func_003C7DF0(a0);
    }
    if (D_00264F80[0] == *(s32 *)(v + 80)) {
        func_00455FC8(func_003C8200, a0);
    }
}
