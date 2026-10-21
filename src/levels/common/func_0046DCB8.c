#include "common.h"

/* localdecomp:start func_0046DCB8 */
typedef int Q_46DCB8 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z;
    u8 pad[0x0C - 0x0C];
    f32 f12;
    f32 f16;
    u8 b20;
    u8 b21;
    u8 pad22[6];
    void *fn;
} S_46DCB8;
extern u8 *D_0022129C[];
extern u8 *func_0045E438(s32);
extern s32 func_00440848(s32);
extern void func_0046DE20(void);

u8 *func_0046DCB8(Q_46DCB8 *a0, f32 *a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 f12, f32 f13, f32 f14) {
    u8 *p = func_0045E438(0x61);
    if (p != 0) {
        u8 *q;
        *(Q_46DCB8 *)(p + 0x10) = *a0;
        p[9] = 0x44;
        *(s32 *)(p + 4) = (t1 << 24) | a3;
        p[1] = 0;
        p[3] = 0x48;
        *(f32 *)(p + 0xC) = f12;
        p[8] = func_00440848(0xFF);
        p[2] = D_0022129C[0][t3];
        *(s16 *)(p + 0xA) = a2;
        *(f32 *)(p + 0x20) = a1[0];
        q = p + 0x20;
        *(f32 *)(q + 4) = a1[1];
        *(f32 *)(q + 8) = a1[2];
        *(f32 *)(q + 0xC) = f14;
        q[0x15] = t0;
        *(f32 *)(q + 0x10) = (f13 - f12) / (f32)a2;
        q[0x14] = (t2 - t1) / a2;
        *(void **)(q + 0x1C) = (void *)func_0046DE20;
    }
    return p;
}
/* localdecomp:end func_0046DCB8 */
