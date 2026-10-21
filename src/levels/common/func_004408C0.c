#include "common.h"

/* localdecomp:start func_004408C0 */
extern s32 func_0013D3E0(void);
f32 func_004408C0(f32 a, f32 b) {
    return a + (f32)func_0013D3E0() * (b - a) * (1.0f / 32768.0f);
}
/* localdecomp:end func_004408C0 */
