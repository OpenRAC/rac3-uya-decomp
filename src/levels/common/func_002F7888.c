#include "common.h"
typedef struct {
    float a[4];
    float b[4];
} Pair_002F7888;
typedef struct {
    u8 pad[16];
    float f;
    u8 pad2[8];
} Src_002F7888;
extern s32 D_001DC300;
extern Pair_002F7888 D_0026E0D0[];
extern Src_002F7888 D_002BE748[];
extern void func_0040CAC0(float *, s32, float);
void func_002F7888(void) {
    s32 i;
    if (D_001DC300 == 0) {
        for (i = 0; i < 10; i++) {
            func_0040CAC0(D_0026E0D0[i].a, 0, D_002BE748[i].f);
            func_0040CAC0(D_0026E0D0[i - 1].b, 0, -D_002BE748[i].f);
        }
        D_001DC300 = 1;
    }
}
