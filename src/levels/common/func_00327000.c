#include "common.h"
extern void *func_00445F18();
extern void func_003B4AE0(s32, void *);
void func_00327000(void *p) {
    func_003B4AE0(*(s32 *)((u8 *)func_00445F18() + 8), p);
}
