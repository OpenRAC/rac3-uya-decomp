#include "common.h"
extern u8 D_001D545C;
extern u8 D_001426E0[];
extern u8 D_00142660[];
extern u8 D_001A4BE0[];
extern void func_00405020(s32 a0, s32 a1);
void func_0034A788(s32 a0) {
    u8 c = D_001D545C;
    u8 *p = D_001426E0;
    u8 *g = D_001A4BE0;
    u8 *q;
    s32 *w;
    s32 i;
    p[80] = c;
    p[82] = 0;
    p[85] = 0;
    p[86] = 0;
    *(s32 *)(g + 6904) = 0;
    p[87] = 0;
    *(s32 *)(g + 6968) = 0;
    q = D_00142660;
    *(s16 *)(q + 114) = 0;
    *(s16 *)(q + 112) = 0;
    q[116] = 0;
    q[118] = 0;
    q[117] = 0;
    q[119] = 0;
    w = (s32 *)(q + 108);
    for (i = 3; i >= 0; i--) {
        *w-- = 0;
    }
    func_00405020(a0, 1);
}
