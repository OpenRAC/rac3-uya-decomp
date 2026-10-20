#include "common.h"
typedef int s128_3C1EE0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x20]; u8 b20; } M_3C1EE0;
extern void func_00437698(M_3C1EE0 *, s32, s128_3C1EE0 *);
extern void func_004082B0(void *, s32, u32, s32, f32, f32, f32);
void func_003C1EE0(M_3C1EE0 *m) {
    s128_3C1EE0 v;
    u32 col;
    if (m == 0) {
        return;
    }
    if (m->b20 == 254) {
        return;
    }
    if (m->b20 == 253) {
        return;
    }
    col = (m->b20 == 5) ? 0x40202080 : 0x40802020;
    func_00437698(m, 2, &v);
    func_004082B0(&v, 11, col, 1, 0.1f, 0.08f, 0.0f);
    func_00437698(m, 3, &v);
    func_004082B0(&v, 11, col, 1, 0.1f, 0.08f, 0.0f);
}
