#include "common.h"
extern void *func_00490968(s32);
void func_0049EFE8(void) {
    void *o = func_00490968(1);
    ((void (*)(void *))(*(void ***)((u8 *)o + 0x4))[3])(o);
}
