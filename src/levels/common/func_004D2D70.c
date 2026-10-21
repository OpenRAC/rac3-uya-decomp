#include "common.h"

/* localdecomp:start func_004D2D70 */
extern void func_0011F0A0();

typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x90]; s32 tbl[1]; } B_3B6F28;
extern B_3B6F28 *D_001EA9D8_003B6F28[];
typedef struct { s32 a[1]; } A_3B6F28;
extern s32 D_001E12C8_003B6F28[2];
extern s32 D_001E12F0_003B6F28[2];
extern s32 D_001E12A0_003B6F28[2];
typedef struct { u8 pad[0xA4]; u32 fA4; } S_1A30B0_3B6F28;
extern S_1A30B0_3B6F28 D_001A30B0;
extern void func_004D2130();
extern void func_0011F0A0();
extern void func_0013BED0();
void func_004D2D70(s32 n, s32 *list) {
    s32 local[12];
    B_3B6F28 *base;
    u8 *e;
    s32 i;
    s32 *pa, *pb;
    s32 *idx;
    s32 *lp;
    s32 m;
    m = -1;
    base = D_001EA9D8_003B6F28[0];
    e = (u8 *)base + base->f8;
    idx = D_001E12C8_003B6F28;
    pb = D_001E12F0_003B6F28;
    pa = idx;
    for (i = 9; i >= 0; i--) {
        *pa++ = m;
        *pb++ = m;
    }
    if (list == 0) {
        for (i = 0; i < n; i++) local[i] = i;
        list = local;
    }
    D_001A30B0.fA4 = 0xFFFFFFFFU;
    if (n > 0) {
        u8 *e18 = e + 0x18;
        A_3B6F28 *t = (A_3B6F28 *)base->tbl;
        s32 c = 0xC000;
        lp = list;
        i = n;
        do {
            u8 *q = e18 + t->a[*lp++];
            *(s32 *)(q + 0x2C) = c;
            *(s32 *)(q + 0x28) = c;
        } while (--i);
    }
    func_0011F0A0(0);
    for (i = 0; i < n; i++) {
        s32 k = list[i];
        idx[k] = i;
        func_004D2130(e + base->tbl[k], &D_001E12A0_003B6F28[i]);
    }
    func_0013BED0();
}
/* localdecomp:end func_004D2D70 */
