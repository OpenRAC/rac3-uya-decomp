#include "common.h"

/* localdecomp:start func_00595BA8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00595BA8;
extern f32 func_00590318(f32, f32);
extern void func_0056F408(s32, u8 *);
extern void func_0056F478(s32, V_00595BA8 *);
void func_00595BA8(u8 *o, s32 a) {
    V_00595BA8 v;
    V_00595BA8 t;
    *(u128_t *)&t = 0;
    t.y = *(f32 *)(o + 0x60);
    t.z = *(f32 *)(o + 0x40);
    v = t;
    v.y = func_00590318(v.y, *(f32 *)(o + 0xD4));
    v.z = func_00590318(v.z, *(f32 *)(o + 0xD8));
    func_0056F408(a, o + 0x30);
    func_0056F478(a, &v);
}
/* localdecomp:end func_00595BA8 */
