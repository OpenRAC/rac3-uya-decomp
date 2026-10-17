#include "common.h"

typedef int u128_3D6FB0 __attribute__((mode(TI)));
struct M_3D6FB0;
typedef struct { struct M_3D6FB0 *arr[15]; s16 h3C; u8 p3E[2]; f32 f40; f32 f44; u8 b48; u8 b49; u8 b4A; u8 b4B; } V_3D6FB0;
typedef struct M_3D6FB0 {
    u8 p0[0x10]; u128_3D6FB0 pos; u8 p20[0x10];
    u8 b30; u8 b31; s16 h32; u8 p34[0x34]; V_3D6FB0 *w68;
} M_3D6FB0;
extern M_3D6FB0 *func_00435E70(s32, s32);
extern s32 func_00440848(s32);
extern void func_00441FB8(M_3D6FB0 *, s32, s32);

M_3D6FB0 *func_003D6FB0(s32 n, M_3D6FB0 **list, s32 chance, s32 a, s32 b, f32 x, f32 y) {
    M_3D6FB0 *m;
    V_3D6FB0 *v;
    s32 i;
    m = func_00435E70(7383, 80);
    if (m == 0) return 0;
    if (n == 0 || list == 0) return 0;
    if (list[0] == 0) return 0;
    v = m->w68;
    m->h32 = 0xFF;
    m->b30 = 0xFF;
    m->pos = list[0]->pos;
    v->f40 = x;
    v->b48 = a;
    v->b49 = b;
    v->f44 = y;
    v->b4A = 0;
    v->b4B = 0;
    for (i = 0; i < n; i++) {
        if (list[i] != 0 && func_00440848(100) < chance) {
            v->arr[v->h3C] = list[i];
            v->h3C++;
        }
    }
    func_00441FB8(m, 0, -1);
    return m;
}
