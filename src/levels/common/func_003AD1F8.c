#include "common.h"

typedef struct {
    u8 pad0[0xB0];
} S_3AD1F8c;

typedef struct {
    u8 pad0[0x270];
    S_3AD1F8c arr[8];
    u8 x7F0[0x10];
} S_3AD1F8b;

typedef struct {
    u8 pad0[0x68];
    S_3AD1F8b *p68;
} S_3AD1F8;

extern void func_003F7B98(S_3AD1F8c *a0, u8 *a1);
extern void func_003F7C40(S_3AD1F8c *a0, u8 *a1);

void func_003AD1F8(S_3AD1F8 *a0) {
    S_3AD1F8b *p = a0->p68;
    s32 i;
    for (i = 0; i < 8; i++) {
        func_003F7B98(&p->arr[i], p->x7F0);
        func_003F7C40(&p->arr[i], p->x7F0);
    }
}
