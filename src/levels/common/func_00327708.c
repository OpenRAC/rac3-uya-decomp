#include "common.h"
extern u8 *func_003252E8(void *);
extern void func_00453210(void *, s32);
void func_00327708(u8 *a0) {
    u8 *v = func_003252E8(a0);
    func_00453210(a0, *(s32 *)(*(u8 **)(v + 104) + 36));
}
