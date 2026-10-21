#include "common.h"

/* localdecomp:start func_00513758 */
extern s32 func_00513758();
extern s32 func_00511E28(void *);
extern void *func_00511BF8();
extern s32 func_00511E28();

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2E60;
extern S_3E2E60 D_001E1660_003E2E60;
extern void *func_00511BF8();
extern s32 func_00511E28();
extern s32 func_005112B8();
s32 func_00513758(s32 a) {
    S_3E2E60 *q;
    s32 r = 0;
    s32 t;
    if (D_001E1660_003E2E60.x4) q = &D_001E1660_003E2E60;
    else q = func_00511BF8(&D_001E1660_003E2E60);
    t = func_00511E28(q);
    if (t) r = func_005112B8(t, a);
    return r;
}
/* localdecomp:end func_00513758 */
