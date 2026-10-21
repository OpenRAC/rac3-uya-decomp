#include "common.h"

/* localdecomp:start func_00345D00 */
extern void func_00437698(s32, s32, f32 *);
extern void func_00345D48(f32 *, f32, f32, f32, f32);

void func_00345D00(s32 a) {
    f32 v[4];
    func_00437698(a, 1, v);
    func_00345D48(v, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_00345D00 */
