#include "common.h"

typedef struct {
    u8 pad0[0x8];
    u8 unk8;
    u8 pad9[0x77];
} D_0049C950_t;

typedef struct {
    u8 pad0[0x1A41];
    u8 unk1A41;
} func_006197C0_t;

typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} func_005FFAA8_buf;

extern func_006197C0_t *func_006197C0(s32);
extern u8 D_00483AC0[];
extern D_0049C950_t D_0049C950[];

void func_005FFAA8(s32 arg0, s32 arg1, u32 *arg2, u32 *arg3, u32 *arg4) {
    func_005FFAA8_buf buf;
    func_006197C0_t *p;
    s32 n;
    u8 *q;
    u8 *d;
    s32 k;
    s32 i;
    u16 bits;
    s32 m;
    u32 a;
    u32 b;

    *arg2 = 0;
    *arg3 = 0;
    p = func_006197C0(arg0);
    q = &p->unk1A41;
    if (p->unk1A41 == 0) {
        bits = 0;
    } else {
        n = p->unk1A41;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 24; i += 3) {
            *d++ = D_00483AC0[((k + i) & 7) * 209 + m];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
        bits = buf.h[2];
    }
    *arg4 = (((s16)bits >> arg1) & 1) ? 0x70D04040 : 0x706EC8FF;
    if (((D_0049C950_t *)((arg1 << 7) + (u32)D_0049C950))->unk8 != 0) {
        *arg2 = 0x706EC8FF;
        *arg3 = 0x706EC8FF;
    }
}
