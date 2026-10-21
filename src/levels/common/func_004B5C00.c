#include "common.h"

/* localdecomp:start func_004B5C00 */
typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x34 - 0x21];
    u16 h34;
    u8 p36[0xAA - 0x36];
    s16 hAA;
    u8 pAC[0x100 - 0xAC];
} M_004B5C00;

extern M_004B5C00 *D_001E00A0[];

void func_004B5C00(s32 a0) {
    M_004B5C00 *m;
    for (m = D_001E00A0[0]; m->b20 != 0xFF; m++) {
        if (m->b20 & 0x80) {
            continue;
        }
        if (m->hAA == 6202 || m->hAA == 6204) {
            if (a0) {
                m->h34 |= 0x80;
            } else {
                m->h34 &= ~0x80;
            }
        }
    }
}
/* localdecomp:end func_004B5C00 */
