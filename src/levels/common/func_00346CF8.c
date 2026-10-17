#include "common.h"
extern void func_0040C0F0(f32 s, void *dst, void *src);
extern void func_0040BF20(void *dst, void *a, void *b);
void func_00346CF8(u8 *a0, void *a1) {
    f32 one = 1.0f;
    func_0040C0F0(one, a0 + 192, *(void **)(a0 + 104));
    func_0040BF20(a0 + 208, a0 + 192, a1);
    func_0040C0F0(one, a0 + 208, a0 + 208);
    func_0040BF20(a0 + 224, a0 + 208, a0 + 192);
}
