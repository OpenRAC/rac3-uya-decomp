#include "common.h"

/* localdecomp:start func_0038E070 */
typedef unsigned int u128_0038E070 __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0038E070;

typedef struct {
    u8 pad0[0x10];
    V4_0038E070 pos;
    u8 pad20[0x48];
    s32 *p68;
} O_0038E070;

extern u128_0038E070 D_002917D0[][4][137];
extern f32 D_0029C310[][4][137];
extern V4_0038E070 D_0029EEE0[][4];
extern s32 D_0029EE80[][4];
extern s32 D_0029EDE0[][4];
extern s32 D_0029EE30[][4];
extern f32 D_001E1FD0[2];
extern s32 D_001E1FE8[2];
extern f32 D_001E2000[2];
extern s32 D_001E2060[2];
extern s32 D_001E2018[2];
extern f32 D_001E2030[2];
extern f32 D_001E2048[2];

extern f32 func_004408C0(f32, f32);
extern s32 func_0013D3E0(void);

void func_0038E070(O_0038E070 *obj) {
    s32 *p = obj->p68;
    s32 i, j;
    f32 f;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 137; j++) {
            f = func_004408C0(0.5f, 4.0f);
            __asm__("sq $0,%0" : "=m"(*(u128_0038E070 *)((u8 *)D_002917D0 + (j * 16 + (*p * 8768 + i * 2192)))));
            D_0029C310[*p][i][j] = f;
        }
        *(V4_0038E070 *)((u8 *)D_0029EEE0 + (i * 16 + *p * 64)) = obj->pos;
        D_0029EE80[*p][i] = 6;
        D_0029EDE0[*p][i] = func_0013D3E0() % 128 + 128;
        D_0029EE30[*p][i] = func_0013D3E0() % 2 + 6;
        D_0029EEE0[*p][i].x += func_004408C0(0.0f, 0.5f) + -0.25f;
        D_0029EEE0[*p][i].y += func_004408C0(0.0f, 0.5f) + -0.25f;
        D_0029EEE0[*p][i].z += func_004408C0(0.0f, 0.5f) + -0.25f;
    }
    D_001E1FD0[*p] = 0.01f;
    D_001E1FE8[*p] = 128;
    D_001E2000[*p] = 0.1f;
    D_001E2060[*p] = 6;
    D_001E2018[*p] = 128;
    D_001E2030[*p] = 0.0f;
    D_001E2048[*p] = 0.0f;
}
/* localdecomp:end func_0038E070 */
