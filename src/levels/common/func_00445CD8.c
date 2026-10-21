#include "common.h"

/* localdecomp:start func_00445CD8 */
extern void func_0040C0F0(f32 *, f32 *, f32);
void func_00445CD8(f32 (*m)[4]) {
    f32 v[4] __attribute__((aligned(16)));
    s32 i;
    s32 j;
    for (i = 0; i < 3; i++) {
        v[3] = 0.0f;
        for (j = 0; j < 3; j++) {
            v[j] = m[j][i];
        }
        func_0040C0F0(v, v, 1.0f);
        for (j = 0; j < 3; j++) {
            m[j][i] = v[j];
        }
    }
}
/* localdecomp:end func_00445CD8 */
