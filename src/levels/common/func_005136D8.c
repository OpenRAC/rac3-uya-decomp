#include "common.h"

/* localdecomp:start func_005136D8 */
extern s32 func_005136D8(s32, s32);
extern s32 func_00511E28(void *);
extern void *func_00511BF8();
extern s32 func_00511E28();

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2DE0;
extern S_3E2DE0 D_001E1660_003E2DE0;
extern void *func_00511BF8();
extern s32 func_00511E28();
extern s32 func_00510C38(s32, s32, s32);
s32 func_005136D8(s32 a, s32 b) {
    S_3E2DE0 *q;
    s32 r = 0;
    s32 t;
    if (D_001E1660_003E2DE0.x4) q = &D_001E1660_003E2DE0;
    else q = func_00511BF8(&D_001E1660_003E2DE0);
    t = func_00511E28(q);
    if (t) r = func_00510C38(t, a, b);
    return r;
}
/* localdecomp:end func_005136D8 */
