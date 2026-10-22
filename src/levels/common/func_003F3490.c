#include "common.h"

/* localdecomp:start func_003F3490 */
extern u8 D_001E2B20[];
extern s32 func_0040BA90(void *);
extern f32 func_004450C0(f32 *, f32, f32);

extern f32 D_001DF9D8_003808E0; typedef struct { u8 pad[0xD4]; f32 fD4; f32 fD8; f32 fDC; u8 fE0[0x460 - 0xE0]; } S_3808E0;
extern f32 func_004450C0(f32 *, f32, f32);
extern s32 func_0040BA90(void *);
void func_003F3490(s32 a) {
    S_3808E0 *s = (S_3808E0 *)(D_001E2B20 + a * 0x460);
    if (s->fD4 != 0.0f) {
        if (s->fDC != 0.0f) {
            func_004450C0(&D_001DF9D8_003808E0 + a, s->fDC, s->fD4);
        } else {
            func_004450C0(&D_001DF9D8_003808E0 + a, s->fDC, s->fD8);
        }
        if ((&D_001DF9D8_003808E0)[a] == s->fDC) {
            if (func_0040BA90(s->fE0) == 1) {
                s->fDC = 0.0f;
            }
        }
        if (s->fDC <= 0.0f && (&D_001DF9D8_003808E0)[a] <= 0.0f) {
            s->fD4 = 0.0f;
        }
    }
}
/* localdecomp:end func_003F3490 */
