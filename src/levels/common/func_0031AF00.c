#include "common.h"

/* localdecomp:start func_0031AF00 */
typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0xF]; u8 b30; u8 b31; u16 h32;
} M_31AF00;
extern M_31AF00 *func_00435E70(s32, s32);
extern M_31AF00 *D_001DC838;

M_31AF00 *func_0031AF00(void) {
    M_31AF00 *m = func_00435E70(3332, 128);
    if (m != 0) {
        s32 c = 0xFF;
        D_001DC838 = m;
        m->b20 = 1;
        m->h32 = c;
        m->b30 = c;
    }
    return m;
}
/* localdecomp:end func_0031AF00 */
