#include "common.h"

typedef struct {
    u8 pad0[0x20];
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x1A06 - 0xA0];
    u8 mode;
} Obj62FA50;

extern void func_0058F600(f32 *, f32 *, f32);
extern void func_0058F7B8(f32 *, f32 *, void *);

void func_0062FA50(Obj62FA50 *o, f32 *dst, f32 *src, f32 scale) {
    switch (o->mode) {
    case 0:
        func_0058F600(dst, src, scale);
        break;
    case 1:
    case 2:
        func_0058F7B8(dst, src, o->m1);
        func_0058F600(dst, dst, scale);
        func_0058F7B8(dst, dst, o->m0);
        break;
    }
}
