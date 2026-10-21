#include "common.h"

/* localdecomp:start func_004D0A58 */
extern s32 func_004D0A58();

extern void func_004D09B8_003AC150();
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; u8 p18[0x2C]; s32 f44; u8 p48[8]; s32 f50; s32 f54; s32 f58; s32 f5C; } O_3AC150;
s32 func_004D0A58(O_3AC150 *o) {
    s32 i = 0;
    o->f44 = 1;
    o->fC = 0;
    o->f10 = 0;
    o->f14 = 0;
    o->f58 = 0;
    o->f5C = 0;
    if (o->f54 > 0) {
        long m = -1;
        s32 off = 0;
        do {
            i++;
            *(long *)(off + o->f50) = m;
            *(long *)(off + o->f50 + 8) = m;
            *(s32 *)(off + o->f50 + 0x10) = 0;
            *(s32 *)(off + o->f50 + 0x14) = 0;
            off += 0x18;
        } while (i < o->f54);
    }
    i = 0;
    while (i < o->f8) {
        func_004D09B8_003AC150((unsigned long *)(o->f4 + i * 16), (o->f0 + i * 0x800) & 0xFFFFFFF, 3, 0x80);
        i++;
    }
    func_004D09B8_003AC150((unsigned long *)(o->f4 + i * 16), o->f4 & 0xFFFFFFF, 2, 0);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = o->f0 & 0xFFFFFFF;
    *(volatile u32 *)0x1000B430 = o->f4 & 0xFFFFFFF;
    func_004D0948(5);
    return 1;
}
/* localdecomp:end func_004D0A58 */
