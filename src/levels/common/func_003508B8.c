#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern void func_0041EDE8(void *, void *, void *);
extern void func_0041EFF8(void *, void *, f32);
void func_003508B8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    *(u128_t *)(s + 752) = *(u128_t *)(s + 960);
    func_0041EDE8(s + 736, s + 752, s + 720);
    func_0041EFF8(s + 736, s + 736, 1.0f);
    func_0041EDE8(s + 720, s + 736, s + 752);
    *(s32 *)(s + 732) = 0;
    *(s32 *)(s + 748) = 0;
    *(s32 *)(s + 764) = 0;
}
