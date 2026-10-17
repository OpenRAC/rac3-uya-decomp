#include "common.h"

typedef int u128_48EF48 __attribute__((mode(TI)));

typedef struct {
    u128_48EF48 pos;
    f32 x10;
    f32 x14;
    f32 x18;
    s32 x1C;
} E_48EF48;

extern void func_0048FC48(void *);
extern s32 D_002487A4;
extern u8 D_00243518[];
extern E_48EF48 D_00291860[];

s32 func_0048EF48(u128_48EF48 *a0, f32 f12, f32 f13, f32 f14) {
    E_48EF48 *e;
    if (D_002487A4 >= 128) {
        func_0048FC48(D_00243518);
    }
    e = &D_00291860[D_002487A4++];
    e->pos = *a0;
    e->x10 = f12;
    e->x14 = f13;
    e->x18 = f14;
    return e->x1C;
}
