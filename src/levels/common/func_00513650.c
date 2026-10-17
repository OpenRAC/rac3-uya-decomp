#include "common.h"

extern void func_00513650();
extern void *func_00511BF8();

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2D90;
extern S_3E2D90 D_001E1660_003E2D90;
extern void *func_00511BF8();
extern void func_00511E50();
void func_00513650(s32 a) {
    S_3E2D90 *q;
    if (D_001E1660_003E2D90.x4) q = &D_001E1660_003E2D90;
    else q = func_00511BF8(&D_001E1660_003E2D90);
    func_00511E50(q, a);
}
