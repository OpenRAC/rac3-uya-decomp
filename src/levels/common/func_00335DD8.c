#include "common.h"

/* localdecomp:start func_00335DD8 */
typedef struct { u8 pad[0x94]; u8 *(*fn)(s32); } V_335DD8;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad44[0xC]; s32 x50; u8 pad54[0x18]; s32 x6C; } S_335DD8;
typedef struct { u8 pad[0x68]; S_335DD8 *x68; } O_335DD8;
extern V_335DD8 *func_00438488(s32, s32, s32);
extern s32 func_00440878(s32, s32);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern s32 D_001E009C[];
void func_00335DD8(O_335DD8 *o, f32 a, f32 b, f32 c) {
    S_335DD8 *s = o->x68;
    V_335DD8 *v = func_00438488(s->x40, 4, 156);
    u8 *m = v->fn(D_001E009C[0] + (s->x50 << 8));
    s->x6C = func_00440878(1, 6);
    *(f32 *)(m + 0x480) = c;
    *(f32 *)(m + 0x484) = func_0040CEC8(a, func_004408C0(-0.008726646f, 0.008726646f));
    *(f32 *)(m + 0x488) = func_0040CEC8(a, b);
    *(f32 *)(m + 0x48C) = func_004408C0(4.0f, 6.0f);
}
/* localdecomp:end func_00335DD8 */
