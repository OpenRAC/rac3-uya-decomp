#include "common.h"

/* localdecomp:start func_003899C0 */
typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;

extern s32 func_0050DA08(s32);
extern void func_004C3500(u8 *, u8 *, s32, s32, f32);

void func_003899C0(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_0050DA08(-1)) {
        func_004C3500(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_003899C0 */
