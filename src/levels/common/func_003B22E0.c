#include "common.h"

typedef int u128_3B22E0 __attribute__((mode(TI)));
extern u8 *func_0040C9B0(s32, s32);
extern s32 func_00417078(s32);
extern void func_00418738(void *, s32, s32);
extern s32 D_001DECB4;

typedef struct {
    s32 list[15];
    s16 count;
    u8 pad3E[2];
    f32 f40;
    f32 f44;
    u8 b48;
    u8 b49;
    u8 b4A;
    u8 b4B;
} Vars_3B22E0;

u8 *func_003B22E0(s32 n, u8 **arr, s32 unused, f32 x, s32 c, s32 d, f32 y) {
    u8 *moby;
    Vars_3B22E0 *v;
    s32 lim;
    s32 i;

    moby = func_0040C9B0(7383, 80);
    if (moby == 0) return 0;
    if (n == 0 || arr == 0) return 0;
    if (arr[0] == 0) return 0;
    v = *(Vars_3B22E0 **)(moby + 104);
    {
        s32 k = 255;
        *(s16 *)(moby + 50) = k;
        moby[48] = k;
    }
    *(u128_3B22E0 *)(moby + 16) = *(u128_3B22E0 *)(arr[0] + 16);
    v->b48 = c;
    v->b49 = d;
    v->b4A = 1;
    v->b4B = 0;
    v->f40 = x;
    v->f44 = y;
    lim = D_001DECB4;
    v->count = n;
    for (i = 0; i < n; i++) {
        if (v->list[i] != 0 && func_00417078(100) < lim) {
            v->list[v->count] = (s32)arr[i];
        }
    }
    func_00418738(moby, 0, -1);
    return moby;
}
