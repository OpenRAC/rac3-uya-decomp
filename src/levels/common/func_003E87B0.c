#include "common.h"

/* localdecomp:start func_003E87B0 */
extern void func_003E7A70(u8 *);
extern void func_003E7478(u8 *, f32 *, f32 *);
extern void func_003E7668(u8 *, f32, f32);
extern void func_003E64E0(u8 *);
extern void func_003E82F8(u8 *);
extern void func_003E7B50(u8 *);

void func_003E87B0(u8 *a0) {
    f32 v[2];

    func_003E7A70(a0);
    func_003E7478(a0, &v[0], &v[1]);
    func_003E7668(a0, v[0], v[1]);
    func_003E64E0(a0);
    func_003E82F8(a0);
    func_003E7B50(a0);
}
/* localdecomp:end func_003E87B0 */
