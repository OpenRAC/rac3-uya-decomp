#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_00446B60(s32, s32, f32 *);
extern void func_0041C480(void *, s32, s32);
extern void func_00446790(s32, s32, void *);

void func_003B8E10(s32 a, u8 *b) {
    f32 buf[4];
    u8 *q = b + 0x50;
    func_00446B60(a, 1, buf);
    __asm__("sq $0, %0" : "=m"(*(u128_t *)(b + 0x90)));
    *(s32 *)(b + 0xC) = 0;
    *(f32 *)(b + 0x8) = buf[2];
    func_0041C480(q, 0, 0x40);
    func_00446790(a, 1, q);
}
