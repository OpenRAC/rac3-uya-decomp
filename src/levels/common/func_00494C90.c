#include "common.h"

/* localdecomp:start func_00494C90 */
typedef struct { u8 p0[0x20]; s32 x[4]; s32 y[4]; s32 z[4]; } O_B45B0;
extern void func_00495F40(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_00495F60(void *, f32, f32, f32, f32);
extern void func_00495850(void *, s32, f32, f32, f32);
void *func_00494C90(void *p) {
    s32 *a = (s32 *)p;
    O_B45B0 *o = (O_B45B0 *)p;
    s32 i;
    a[1] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    for (i = 0; i < 4; i++) {
        o->x[i] = 0;
        o->y[i] = 0;
        o->z[i] = 0;
    }
    *(f32 *)((u8 *)p + 0xA0) = 0.01f;
    a[0x14] = 0;
    a[0x15] = 0;
    *(s8 *)p = 0;
    a[0x16] = 0;
    *(f32 *)((u8 *)p + 0xA4) = 0.006667f;
    func_00495F60(p, 0.5f, 0.6f, 1.0f, 0.41f);
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_00495F40)(p, 1, 0.5f, 0.99f, 0.045f, 0.48f, 0.35f);
    func_00495850(p, 1, 0.0265f, 0.00666f, 0.01f);
    *(s8 *)((u8 *)p + 0xA9) = 0;
    a[0x1E] = 0;
    return p;
}
/* localdecomp:end func_00494C90 */
