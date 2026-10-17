#include "common.h"
extern s32 func_003252E8(void);
extern void func_003252F0(s32, s32);
void func_003270B0(void) {
    s32 v = func_003252E8();
    func_003252F0(v, *(s32 *)(v + 104));
}
