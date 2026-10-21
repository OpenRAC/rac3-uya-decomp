#include "common.h"

/* localdecomp:start func_0030D618 */
extern void func_0040BE90(f32 *, f32 *, f32);
void func_0030D618(f32 *m, f32 s) {
    func_0040BE90(m, m, s);
    func_0040BE90(m + 4, m + 4, s);
    func_0040BE90(m + 8, m + 8, s);
    func_0040BE90(m + 12, m + 12, s);
}
/* localdecomp:end func_0030D618 */
