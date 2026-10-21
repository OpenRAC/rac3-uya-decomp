#include "common.h"

/* localdecomp:start func_0044C658 */
typedef struct {
    u8 pad0[0x48];
    s16 h48;
    u8 b4A;
    u8 pad4B;
    u8 b4C;
    u8 pad4D[3];
} S_44C658;

extern u8 *D_001E009C[];
extern u8 *D_001E0F54[];
extern u8 *D_001E0E48[];
extern void func_00436220(u8 *);
extern void func_004A6DF8(u8 *, s32);

void func_0044C658(S_44C658 *p, s32 a1) {
    u8 *o;
    do {
        switch (p->b4C & 3) {
        case 0:
            o = D_001E009C[0] + (p->h48 << 8);
            if (a1 != 0) {
                func_00436220(o);
            } else {
                *(s32 *)(o + 0x98) = 0;
                *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
                func_004A6DF8(o, 1);
                *(u16 *)(o + 0x34) |= 2;
            }
            break;
        case 1:
            (D_001E0F54[0] + (p->h48 << 5))[0x1C] = 0;
            break;
        case 2:
            (D_001E0E48[0] + (p->h48 << 5))[0x16] |= 1;
            break;
        }
    } while ((p++)->b4A != 1);
}
/* localdecomp:end func_0044C658 */
