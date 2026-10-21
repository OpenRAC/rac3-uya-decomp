#include "common.h"

/* localdecomp:start func_003723E0 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_00372408(u8 *, u128_t *);

void func_003723E0(u8 *obj) {
    u128_t v;
    v = **(u128_t **)(obj + 104);
    func_00372408(obj, &v);
}
/* localdecomp:end func_003723E0 */
