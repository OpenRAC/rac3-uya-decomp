#include "common.h"

/* localdecomp:start func_004D0FF8 */
extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);
extern void func_004D0948(s32);
extern void func_004D08D8(s32);

typedef struct { u32 f0; u32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; u32 f1C; u32 f20; u32 f24; u32 f28; u32 f2C; u32 f30; u32 f34; u32 f38; u32 f3C; s32 f40; s32 f44; } O_3AC6F0;
extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);
extern void func_004D0948(s32);
extern void func_004D08D8(s32);
extern s32 func_004D0890();
s32 func_004D0FF8(O_3AC6F0 *p) {
    u32 v = p->f38;
    u32 bits = v & 0x7F;
    u32 t = ((v >> 16) & 3) + ((v >> 8) & 0xF);
    u32 madr = p->f1C - t * 16;
    u32 qwc = p->f24 + t;
    u32 chcr = p->f28 | 0x100;
    u32 tadr = p->f20;
    func_0011EE60(p->f40);
    if (madr < p->f0) {
        s32 tag;
        s32 m;
        qwc = (p->f0 - madr) >> 4;
        tadr = p->f4 & 0xFFFFFFF;
        madr += p->f8 << 11;
        tag = 0;
        if (p->f1C != p->f0) {
            tag = p->f1C == p->f0 + (p->f8 << 11) ? 0 : 3;
        }
        chcr = (p->f28 & 0xFFFFFFF) | (tag << 28) | 0x100;
        m = (p->f8 - p->fC) % p->f8;
        if (m < 0 || m >= p->f10) {
            p->fC = p->f8 - 1;
            p->f10 = p->f10 + 1;
        }
    } else {
        s32 a = func_004D0890(p, p->f1C);
        s32 b = func_004D0890(p, madr);
        if (a != b) {
            s32 tag;
            s32 m;
            tadr = (p->f4 + a * 16) & 0xFFFFFFF;
            qwc = (p->f0 + (a << 11) - madr) >> 4;
            tag = p->f0 + (p->f1C - p->f0) % (u32)(p->f8 << 11) == p->f0 + (((p->fC + p->f10) % p->f8) << 11) ? 0 : 3;
            chcr = (p->f28 & 0xFFFFFFF) | (tag << 28) | 0x100;
            m = (b + p->f8 - p->fC) % p->f8;
            if (m < 0 || m >= p->f10) {
                p->fC = b;
                p->f10 = p->f10 + 1;
            }
        }
    }
    if (p->f2C != 0 && p->f30 != 0) {
        *(volatile u32 *)0x1000B010 = p->f2C;
        *(volatile u32 *)0x1000B020 = p->f30;
        func_004D08D8(p->f34 | 0x100);
    }
    if (p->f10 != 0) {
        if (*(volatile s32 *)0x10002010 < 0) { do {} while (*(volatile s32 *)0x10002010 < 0); }
        *(volatile u32 *)0x10002000 = bits;
        if (*(volatile s32 *)0x10002010 < 0) { do {} while (*(volatile s32 *)0x10002010 < 0); }
    }
    *(volatile u32 *)0x1000B410 = madr;
    *(volatile u32 *)0x1000B430 = tadr;
    *(volatile u32 *)0x1000B420 = qwc;
    if (p->f10 != 0) {
        func_004D0948(chcr);
    }
    *(volatile u32 *)0x10002010 = p->f3C;
    p->f44 = 1;
    func_0011EE40(p->f40);
    return 1;
}
/* localdecomp:end func_004D0FF8 */
