#include "common.h"

extern long func_003EA150(s32);
extern void func_004A6DD8(s32, long);

void func_00357FD0(long *a, u8 *b) {
    *(long *)(b + 136) = a[0];
    *(long *)(b + 112) = a[1];
    *(long *)(b + 120) = func_003EA150(*(s32 *)(a + 4));
    *(long *)(b + 128) = a[3];
    func_004A6DD8(71, a[2]);
}
