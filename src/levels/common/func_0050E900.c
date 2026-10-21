#include "common.h"

/* localdecomp:start func_0050E900 */
extern u8 D_001A4BE0[];

extern u8 *func_00435E70(s32 a0, s32 a1);
extern void func_004E1518(s32 a0);
extern void func_004E7FD8(s32 a0);

void func_0050E900(s32 arg0) {
    u8 *g = D_001A4BE0;
    u8 *g2;
    u8 *m;
    u8 *p;

    *(s32 *)(g + 4808) = 23;
    if (*(s32 *)(g + 4768) == 0) {
        m = func_00435E70(1290, 128);
        if (m != 0) {
            *(s16 *)(m + 50) = 32;
            m[49] = 1;
            *(unsigned long *)(m + 56) = 0x20202000000000L;
            *(u16 *)(m + 52) |= 2;
            *(s32 *)(m + 100) = 0;
            p = *(u8 **)(m + 36);
            if (p != 0 && p[6] != 0) {
                m[99] = 16;
            }
            *(u16 *)(m + 52) |= 0x800;
            g2 = D_001A4BE0;
            *(u8 **)(g2 + 4768) = m;
            *(s32 *)(g2 + 4804) = 2;
        }
    }
    func_004E1518(arg0);
    func_004E7FD8(arg0);
}
/* localdecomp:end func_0050E900 */
