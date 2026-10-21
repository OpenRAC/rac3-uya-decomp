#include "common.h"

/* localdecomp:start func_0033BDC8 */
typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;

extern s32 D_001D545C[];
extern s32 D_001DCFF4;
extern void func_00456960(s32 a0);

void func_0033BDC8(S_33BDC8 *a0) {
    if (D_001D545C[0] == 8) {
        if (a0->f18 < 330.0f) {
            D_001DCFF4++;
        }
        if (D_001DCFF4 >= 46) {
            func_00456960(12);
        }
    }
}
/* localdecomp:end func_0033BDC8 */
