#include "common.h"

typedef struct {
    u8 pad0[0x3DA];
    s16 h3DA;
} S_354D28b;

typedef struct {
    u8 pad0[0x10];
    f32 v10[4];
    u8 pad20[0x68 - 0x20];
    S_354D28b *p68;
} S_354D28;

extern s32 func_00354AF8(S_354D28 *a0);
extern void func_00405688(f32 *a0, f32 *a1);
extern void func_004056C0(f32 *a0, f32 *a1);

void func_00354D28(S_354D28 *a0, S_354D28 *a1) {
    if (a0->p68->h3DA != 0 || func_00354AF8(a0) != 0) {
        func_00405688(a0->v10, a1->v10);
    } else {
        func_004056C0(a0->v10, a1->v10);
    }
}
