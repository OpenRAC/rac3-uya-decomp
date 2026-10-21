#include "common.h"

/* localdecomp:start func_004A0660 */
typedef struct { u8 pad0[0x150]; s16 x; s16 y; } S_3CBC70;
extern S_3CBC70 D_001CFEC0_003CBC70;
extern u32 *D_001E10E8_003CBC70;
void func_004A0660(s32 rgba) {
    S_3CBC70 *s = &D_001CFEC0_003CBC70;
    s32 x = s->x;
    s32 y = s->y;
    s32 n = x / 32;
    s32 i;
    unsigned long *q;
    s32 k;
    D_001E10E8_003CBC70[0] = (n + 5) | 0x10000000;
    D_001E10E8_003CBC70[1] = 0;
    D_001E10E8_003CBC70[2] = 0;
    D_001E10E8_003CBC70[3] = (n + 5) | 0x50000000;
    D_001E10E8_003CBC70 += 4;
    q = (unsigned long *)D_001E10E8_003CBC70;
    q[0] = 0x1000000000000001UL;
    q[1] = 0xE;
    q[2] = 0x35801;
    q[3] = 0x47;
    q[4] = 0x2400000000000001UL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = rgba;
    q[8] = (n | 0x8000) | 0x2400000000000000UL;
    q[9] = 0x44;
    i = 0;
    if (i < n) {
        k = 10;
        do {
            q[k++] = (0x8000 - x * 8 + i * 0x200) | ((unsigned long)(0x8000 - y * 8) << 16);
            q[k++] = (0x8200 - x * 8 + i * 0x200) | ((unsigned long)(y * 8 + 0x7FF0) << 16);
            i++;
        } while (i < n);
    }
    D_001E10E8_003CBC70 += n * 4 + 20;
    D_001E10E8_003CBC70[0] = 0x10000000;
    D_001E10E8_003CBC70[1] = 0;
    D_001E10E8_003CBC70[2] = 0x13000000;
    D_001E10E8_003CBC70[3] = 0;
    D_001E10E8_003CBC70 += 4;
}
/* localdecomp:end func_004A0660 */
