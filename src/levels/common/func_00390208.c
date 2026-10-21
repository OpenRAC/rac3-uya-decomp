#include "common.h"

/* localdecomp:start func_00390208 */
typedef struct {
    u8 pad0[28];
    s32 unk1C;
    u8 pad20[16];
} S_390208a;

typedef struct {
    u8 pad0[68];
    s32 unk44;
    u8 pad48[8];
} S_390208b;

extern u8 *D_001DE028;
extern S_390208a D_0029F020[];
extern S_390208b D_0029F260[];

extern u8 *func_00435E70(s32 a0, s32 a1);
extern s32 func_00421F08(u8 *a0, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16);

void func_00390208(void) {
    u8 *m;
    u8 *v;
    u8 *pos;
    s32 i;

    if (D_001DE028 == 0) {
        m = func_00435E70(6285, 128);
        if (m != 0) {
            m[48] = 255;
            *(s16 *)(m + 50) = 0xFF;
            v = *(u8 **)(m + 104);
            m[32] = 0;
            pos = m + 16;
            for (i = 11; i >= 0; i--) {
                D_0029F020[i].unk1C = 0;
            }
            for (i = 127; i >= 0; i--) {
                D_0029F260[i].unk44 = 0;
            }
            *(s32 *)(v + 16) = func_00421F08(pos, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            D_001DE028 = m;
        }
    }
}
/* localdecomp:end func_00390208 */
