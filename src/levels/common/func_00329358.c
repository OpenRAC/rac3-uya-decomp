#include "common.h"

/* localdecomp:start func_00329358 */
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x13]; u16 h34; } M_329358;
extern void func_00445F18(void);

s32 func_00329358(M_329358 *m) {
    if (!(m->h34 & 2)) return 0;
    func_00445F18();
    return m->b20 == 0xFD;
}
/* localdecomp:end func_00329358 */
