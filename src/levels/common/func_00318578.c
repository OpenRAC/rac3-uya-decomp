#include "common.h"

/* localdecomp:start func_00318578 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xD4];
    u8 *pD4;
} S_318578;

extern void func_003B8D00(s32 a, void *b, void *out, s32 d, f32 e);
extern void func_003E4858(u128_t *out, u128_t *in, f32 s);
extern s32 func_004182E0(s32 lo, s32 hi);
extern f32 func_00418328(f32 lo, f32 hi);
extern f32 func_00418380(f32 lo, f32 hi);
extern u8 *func_004442C8(void *pos, u128_t *vel, s32 life, s32 tex, s32 rot, s32 a, s32 b, f32 size, f32 grow, f32 g, s32 c);
typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
} P_318578;

extern P_318578 D_001A4BE0;
extern S_318578 D_0021E158;
extern u8 D_0026F820[];

void func_00318578(u8 *m, s32 *tex) {
    u8 pos[16];
    u128_t vel;
    u8 *v;
    s32 i;
    s32 rot;
    f32 size;
    u8 *p;

    v = *(u8 **)(m + 0x68);
    for (i = 0; i < 24; i++) {
        func_003B8D00(D_001A4BE0.w25C0, D_0026F820, pos, 0, 0.0f);
        vel = *(u128_t *)(m + 0xE0);
        func_003E4858(&vel, &vel, *(f32 *)(v + 0x14) * 0.033333335f);
        rot = func_00418380(2.0f, 5.0f);
        size = func_00418328(0.05f, 0.1f);
        func_004442C8(pos, &vel, func_004182E0(20, 25) * *(f32 *)(v + 0x14), tex[0], rot, 0x7F, 0x7F,
                      size * 210000.0f, 2100.0f, -0.00083333335f, 1);
        rot = -(rot * 2);
        p = func_004442C8(pos, &vel, func_004182E0(20, 25) * *(f32 *)(v + 0x14), tex[1], rot, 0x30, 0x30,
                          size * 4.0f * 210000.0f, 4200.0f, -0.00083333335f, 0);
        if (p != 0) {
            p[2] = *D_0021E158.pD4;
        }
    }
    *(f32 *)(v + 0x14) += 0.029166669f;
    if (*(f32 *)(v + 0x14) > 1.0f) {
        *(f32 *)(v + 0x14) = 1.0f;
    }
}
/* localdecomp:end func_00318578 */
