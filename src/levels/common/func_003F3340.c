#include "common.h"

/* localdecomp:start func_003F3340 */
typedef struct { u8 pad[0xC8]; f32 fC8; f32 fCC; u8 fD0[0x460 - 0xD0]; } S_3807F0;
extern u8 D_001E2B20[];
extern f32 D_001DF9D0_003807F0[2];
extern f32 func_004450C0(f32 *, f32, f32);
extern s32 func_0040BA90(void *);

void func_003F3340(s32 a) {
    S_3807F0 *s = (S_3807F0 *)(D_001E2B20 + a * 0x460);
    if (s->fC8 != 0.0f) {
        func_004450C0(D_001DF9D0_003807F0 + a, s->fCC, s->fC8);
        if (D_001DF9D0_003807F0[a] == s->fCC) {
            if (func_0040BA90(s->fD0) == 1) {
                s->fCC = 0.0f;
            }
        }
        if (s->fCC <= 0.0f && D_001DF9D0_003807F0[a] <= 0.0f) {
            s->fC8 = 0.0f;
        }
    }
}
/* localdecomp:end func_003F3340 */
