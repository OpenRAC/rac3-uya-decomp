#include "common.h"

/* localdecomp:start func_00327178 */
typedef struct {
    u8 pad[40];
    void (*fn)(u8 *, s32, s32);
} Vt00327178;
extern u8 *func_003252E8(s32);
extern Vt00327178 *func_00438488(s32 a0, s32 a1, s32 a2);
extern u8 *D_001E009C[];
void func_00327178(s32 a0, s32 a1) {
    u8 *s = *(u8 **)(func_003252E8(a0) + 104);
    Vt00327178 *vt;
    if (*(s32 *)(s + 20) == -1) {
        return;
    }
    vt = func_00438488(6877, 0, 104);
    if (a0 == -2) {
        vt->fn(D_001E009C[0] + (*(s32 *)(s + 20) << 8), *(s32 *)(s + 24), a1);
    } else {
        vt->fn(D_001E009C[0] + (*(s32 *)(s + 20) << 8), a0, a1);
    }
}
/* localdecomp:end func_00327178 */
