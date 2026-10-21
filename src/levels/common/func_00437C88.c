#include "common.h"

/* localdecomp:start func_00437C88 */
extern int D_001E10E8_003BDBA0;

typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001E0130;
extern u8 D_0021F260[];
extern u8 D_002E9C10[];
extern u8 D_001DA2F0[];
extern void func_0040BD58();
void func_00437C88(void) {
    u32 *pkt;
    u8 *e;
    if (D_001E0130 == D_0021F260) return;
    pkt = (u32 *)D_001E10E8_003BDBA0;
    D_001E10E8_003BDBA0 = (int)(pkt + 4);
    for (e = D_0021F260; e < D_001E0130; e += 8) {
        u32 *a = *(u32 **)e;
        u32 b = *(u32 *)(e + 4);
        O_3BDEA8 *o;
        T_3BDEA8 *t;
        s32 lo, hi, idx;
        s32 base;
        s32 j;
        a[0] = 0x20000000;
        idx = b & 0xF;
        o = (O_3BDEA8 *)(b & ~0xF);
        a[1] = D_001E10E8_003BDBA0;
        a[3] = 0x11000000;
        t = o->f24;
        hi = t->bB >> 4;
        lo = t->bB & 0xF;
        base = t->f20 - ((lo * hi) << 10) - 0x10;
        for (j = 0; j < hi; j++) {
            s16 h = ((s16 *)base)[j];
            func_0040BD58(D_001E10E8_003BDBA0, D_002E9C10, 0x70);
            ((s16 *)D_001E10E8_003BDBA0)[0x12] = h;
            ((u32 *)D_001E10E8_003BDBA0)[0x19] = base + (idx << 10) + 0x10 + ((j * lo) << 10);
            D_001E10E8_003BDBA0 = D_001E10E8_003BDBA0 + 0x70;
        }
        ((u32 *)D_001E10E8_003BDBA0)[0] = 0x30000003;
        ((u32 *)D_001E10E8_003BDBA0)[1] = (u32)D_001DA2F0;
        ((u32 *)D_001E10E8_003BDBA0)[2] = 0;
        ((u32 *)D_001E10E8_003BDBA0)[3] = 0x50000003;
        D_001E10E8_003BDBA0 = D_001E10E8_003BDBA0 + 0x10;
        ((u32 *)D_001E10E8_003BDBA0)[0] = 0x20000000;
        ((u32 *)D_001E10E8_003BDBA0)[1] = (u32)(a + 4);
        ((u32 *)D_001E10E8_003BDBA0)[2] = 0;
        ((u32 *)D_001E10E8_003BDBA0)[3] = 0;
        D_001E10E8_003BDBA0 = D_001E10E8_003BDBA0 + 0x10;
    }
    pkt[0] = 0x20000000;
    pkt[1] = D_001E10E8_003BDBA0;
    pkt[2] = 0;
    pkt[3] = 0;
}
/* localdecomp:end func_00437C88 */
