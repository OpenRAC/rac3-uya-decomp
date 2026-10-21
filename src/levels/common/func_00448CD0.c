#include "common.h"

/* localdecomp:start func_00448CD0 */
extern void func_00448CD0(f32 *v, f32 r);

extern f32 func_004408C0(f32, f32);
void func_00448CD0(f32 *v, f32 r) {
    v[0] += func_004408C0(-r, r);
    v[1] += func_004408C0(-r, r);
    v[2] += func_004408C0(-r, r);
}
/* localdecomp:end func_00448CD0 */
