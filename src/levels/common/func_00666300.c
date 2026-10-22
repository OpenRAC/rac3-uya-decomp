#include "common.h"

/* localdecomp:start func_00666300 */
typedef int Q_666300 __attribute__((mode(TI)));
typedef struct { u8 b[0x340]; } __attribute__((aligned(16))) A_666300;
typedef struct { s32 w[7]; } B_666300;
extern s32 D_001DAAE8;
extern A_666300 D_00337800[];
extern B_666300 D_0033AC08[];

void func_00666300(void) {
    s32 i;

    D_001DAAE8 = 0;
    for (i = 0; i < 16; i++) {
        u8 *p = D_00337800[i].b;
        *(u32 *)(p + 0x0) = 0xFFFFFFFF;
        __asm__("sq $0, %0" : "=m"(*(Q_666300 *)(p + 0x270)));
        *(s32 *)(p + 0x2D0) = 0;
        __asm__("sq $0, %0" : "=m"(*(Q_666300 *)(p + 0x280)));
        *(s32 *)(p + 0x2D4) = 0;
        *(s32 *)(p + 0x2D8) = 0;
        *(s32 *)(p + 0x2DC) = 0;
        *(s32 *)(p + 0x2F8) = 0;
        *(f32 *)(p + 0x308) = 40.0f;
        *(f32 *)(p + 0x30C) = 40.0f;
        *(s32 *)(p + 0x310) = 0;
        *(s16 *)(p + 0x2FC) = -1;
        *(s16 *)(p + 0x304) = -1;
        *(s32 *)(p + 0x31C) = 0;
        *(s32 *)(p + 0x320) = 0;
        *(s32 *)(p + 0x324) = 0;
        *(s16 *)(p + 0x306) = 0;
    }
    for (i = 0; i < 5; i++) {
        D_0033AC08[i].w[0] = 0;
        D_0033AC08[i].w[1] = 0;
        D_0033AC08[i].w[2] = 0;
        D_0033AC08[i].w[3] = 0;
        D_0033AC08[i].w[4] = 0;
        D_0033AC08[i].w[5] = 0;
        D_0033AC08[i].w[6] = 0;
    }
}
/* localdecomp:end func_00666300 */
