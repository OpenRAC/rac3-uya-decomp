#include "common.h"

typedef struct {
    u8 pad0[352];
    s16 unk160;
    s16 unk162;
    s16 unk164;
    s16 unk166;
    u8 pad168[4];
    u16 unk16C;
    s16 unk16E;
} S_001CFEC0;

typedef struct {
    unsigned long a : 9;
    unsigned long b : 55;
} S_412E30bf;

extern S_001CFEC0 D_001CFEC0[];
extern u32 D_001E10E8;
extern unsigned long D_001D4C30;

extern void func_0040BBD0(u32, s32);
extern void func_0012C638(u32, s32, s32, s32, s32, s32);

void func_00412E30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S_001CFEC0 *g;
    s32 tbw;
    u32 s0;
    u32 s3;
    unsigned long *q;
    unsigned long v;
    s32 n;

    tbw = arg0 - 6;
    if (tbw <= 0) {
        tbw = 1;
    }
    g = D_001CFEC0;
    g->unk166 = arg2 >> 13;
    g->unk160 = 1 << arg0;
    g->unk162 = 1 << arg1;
    D_001D4C30 = (unsigned long)(arg2 >> 8) | ((unsigned long)(1 << tbw) << 14) | ((unsigned long)arg0 << 26) | ((unsigned long)arg1 << 30) | (1L << 34);
    func_0040BBD0(D_001E10E8, 240);
    ((u32 *)D_001E10E8)[0] = 0x1000000E;
    ((u32 *)D_001E10E8)[1] = 0;
    ((u32 *)D_001E10E8)[2] = 0;
    ((u32 *)D_001E10E8)[3] = 0x5000000E;
    D_001E10E8 += 16;
    q = (unsigned long *)D_001E10E8;
    q[0] = 0x1000000000000008L;
    q[1] = 14;
    s0 = D_001E10E8;
    s3 = s0 + 16;
    D_001E10E8 = s3;
    func_0012C638(s3, g->unk164, g->unk160, g->unk162, 3, 0);
    ((S_412E30bf *)(s0 + 16))->a = g->unk166;
    if (arg3 == 0) {
        *(unsigned long *)(s3 + 16) = (long)g->unk16E | ((unsigned long)(g->unk16C & 0xF) << 24);
    } else {
        n = arg0 + arg1;
        if (n >= 17) {
            n = 16;
        }
        *(unsigned long *)(s3 + 16) = (long)((arg2 - (4 << n)) >> 13) | ((unsigned long)(g->unk16C & 0xF) << 24);
    }
    D_001E10E8 += 128;
    q = (unsigned long *)D_001E10E8;
    q[0] = 0x1000000000000001L;
    q[1] = 14;
    q[2] = 0x30003;
    q[3] = 71;
    q[4] = 0x4400000000008001L;
    q[5] = 17424;
    q[6] = 262;
    q[7] = 0;
    q[8] = (long)(0x8000 - (D_001CFEC0[0].unk160 << 3)) | ((long)(0x8000 - (D_001CFEC0[0].unk162 << 3)) << 16);
    q[9] = (long)((D_001CFEC0[0].unk160 << 3) + 0x8000) | ((long)((D_001CFEC0[0].unk162 << 3) + 0x7FF0) << 16);
    D_001E10E8 += 80;
}
