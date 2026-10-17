#include "common.h"

typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0xF]; u8 b30; u8 b31; u16 h32;
} M_34C3F0;
extern M_34C3F0 *func_00435E70(s32, s32);
extern M_34C3F0 *D_001DD418;

M_34C3F0 *func_0034C3F0(void) {
    M_34C3F0 *m = func_00435E70(4406, 128);
    if (m != 0) {
        s32 c = 0xFF;
        D_001DD418 = m;
        m->b20 = 1;
        m->h32 = c;
        m->b30 = c;
    }
    return m;
}
