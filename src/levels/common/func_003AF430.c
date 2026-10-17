#include "common.h"

extern u8 D_001E21C0[];
extern f32 func_003ED318(void *a, void *b);
extern void func_00424620(void *a);

void func_003AF430(u8 *a0)
{
    if (a0[49] != 0) {
        if (func_003ED318(D_001E21C0, a0 + 16) < 1024.0f) {
            func_00424620(a0);
            a0[111] = 30;
        }
    }
}
