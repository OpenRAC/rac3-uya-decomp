#include "common.h"

/* localdecomp:start func_00437720 */
extern void func_0043CE28(void *, s32, void *, void *);
extern void func_0040BE90(void *, void *, f32);

void func_00437720(u8 *a0, s32 a1, void *a2) {
    f32 m[16];
    s32 id;
    f32 s = *(f32 *)(a0 + 44) * 0.0009765625f;
    id = a1;
    func_0043CE28(a0, 1, &id, m);
    func_0040BE90(a2, &m[12], s);
}
/* localdecomp:end func_00437720 */
