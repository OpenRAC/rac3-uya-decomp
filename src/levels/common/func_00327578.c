#include "common.h"

/* localdecomp:start func_00327578 */
typedef struct {
    u8 pad[72];
    s32 (*fn)(u8 *);
} Vt00327578;
extern u8 *func_003252E8(void *);
extern Vt00327578 *func_00438488(s32 a0, s32 a1, s32 a2);
extern u8 *D_001E009C;
s32 func_00327578(void *a0) {
    u8 *s = *(u8 **)(func_003252E8(a0) + 104);
    if (*(s32 *)(s + 20) == -1) {
        return 1;
    }
    return func_00438488(6877, 0, 104)->fn(D_001E009C + (*(s32 *)(s + 20) << 8));
}
/* localdecomp:end func_00327578 */
