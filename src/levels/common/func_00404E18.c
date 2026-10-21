#include "common.h"

/* localdecomp:start func_00404E18 */
extern void func_00403708(s32, s32, s32, s32, unsigned long);

void func_00404E18(s32 x, s32 y, s32 w, s32 z, s32 a, s32 b) {
    s32 c = (a << 24) | b;
    func_00403708(x, y, w, z, c);
    func_00403708(x + 1, y - 1, w - 2, w, c);
    func_00403708(x + 2, y - 2, w - 3, w - 2, c);
    func_00403708(x + 4, y - 4, w - 4, w - 3, c);
    func_00403708(x + 1, y - 1, z, z + 2, c);
    func_00403708(x + 2, y - 2, z + 2, z + 3, c);
    func_00403708(x + 4, y - 4, z + 3, z + 4, c);
}
/* localdecomp:end func_00404E18 */
