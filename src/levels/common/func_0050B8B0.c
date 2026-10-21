#include "common.h"

/* localdecomp:start func_0050B8B0 */
typedef struct {
    u8 pad0[0x43];
    u8 b43;
} S_50B8B0_Obj;

typedef struct {
    u8 pad0[0x2800];
    S_50B8B0_Obj *obj;
    s32 f2804;
} S_50B8B0;

extern S_50B8B0 D_001A4BE0;
extern s32 func_0050B850(s32, s32 *);
extern void func_00441C78(S_50B8B0_Obj *, s32, s32, s32);

void func_0050B8B0(s32 a0, s32 a1, f32 f) {
    S_50B8B0 *s = &D_001A4BE0;
    s32 v;
    if (s->obj == 0) {
        return;
    }
    if (s->f2804 == 0) {
        return;
    }
    if (func_0050B850(a0, &v)) {
        func_00441C78(s->obj, v, a1, (s32)f);
    } else if (s->obj->b43) {
        func_00441C78(s->obj, 0, 0, 7);
    }
}
/* localdecomp:end func_0050B8B0 */
