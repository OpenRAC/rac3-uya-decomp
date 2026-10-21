#include "common.h"

/* localdecomp:start func_004CA1E8 */
typedef struct { u8 pad[136]; u8 b[4]; } Sub_004CA1E8;
typedef struct { u8 pad[20176]; Sub_004CA1E8 s; } Obj_004CA1E8;
extern void func_0011BB58(void *, s32, s32);
extern void func_004C9F98(void *, s32, s32, f32, f32);
void func_004CA1E8(Obj_004CA1E8 *a0, s32 a1, s32 a2) {
    Sub_004CA1E8 *s = &a0->s;
    s32 n = 360;
    if (a2 != -1) n = a2;
    func_0011BB58(s->b, a1, 255);
    func_004C9F98(s, 1, n, 255.0f, 80.0f);
}
/* localdecomp:end func_004CA1E8 */
