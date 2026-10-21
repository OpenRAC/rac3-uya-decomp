#include "common.h"

extern void func_003591B8(void *a0, void *a1);
extern void func_0035AC68(void *a0, void *a1);
extern void func_004135E0(void *fn, void *a1);
extern s32 func_004583F8(void *a0);
extern void func_0035BA20(void);
extern s32 D_001D545C;
extern f32 D_001DD528;
extern s32 D_001DD52C;
extern f32 D_001DD530;
extern s32 D_001DD534;

void func_003590B0(u8 *a0) {
    void *s1;
    s32 t;
    s32 v;

    s1 = *(void **)(a0 + 0x68);
    t = D_001D545C;
    if (t == 0xB && D_001DD528 != 255.0f) {
        v = 0xFF;
        D_001DD534 = v;
        D_001DD528 = 255.0f;
        D_001DD530 = 255.0f;
        goto tail;
    } else if (t == 0x13 && D_001DD528 != 255.0f) {
        v = 0x40;
        D_001DD534 = v;
        D_001DD528 = 64.0f;
        D_001DD530 = 64.0f;
    tail:
        D_001DD52C = v;
    }
    if (func_004583F8(a0 + 0x10) != 0) {
        if (a0[0x20] == 0) {
            func_003591B8(a0, s1);
        }
        if (a0[0x20] == 1) {
            func_0035AC68(a0, s1);
            func_004135E0(func_0035BA20, a0);
        }
    }
}
