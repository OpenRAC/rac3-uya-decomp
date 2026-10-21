#include "common.h"

/* localdecomp:start func_003F2090 */
typedef int u128_t __attribute__((mode(TI)));
#define Q(base, off) (*(u128_t *)((u8 *)(base) + (off)))
#define W(base, off) (*(s32 *)((u8 *)(base) + (off)))
#define F(base, off) (*(float *)((u8 *)(base) + (off)))
extern u8 D_001E2AC0[];
extern void func_00447580(void *, void *);
extern void func_0040C0F0(float *, s32, float);
extern void func_003F1D30(void *, void *, s32, float *, float *, float *);
extern void func_003F2000(s32);
extern void func_003F1F28(s32);
extern void func_003F2058(s32);
void func_003F2090(u8 *obj) {
    float a[4];
    float b[4];
    float c[4];
    s32 idx = W(obj, 0x94);
    u8 *e = D_001E2AC0 + idx * 0x460;
    u8 *p = e + 0x2A0;
    if (*(s16 *)p == 1) {
        if (p[3] == 0) {
            Q(e, 0x2F0) = Q(obj, 0x30);
            func_00447580(e + 0x300, obj);
        } else if (p[3] == 2) {
            Q(e, 0x360) = Q(obj, 0x30);
            func_00447580(e + 0x370, obj);
            func_003F1F28(idx);
        } else {
            func_0040C0F0(a, W(e, 0x240) + 0xC0, 1.0f);
            func_0040C0F0(b, W(e, 0x240) + 0xD0, 1.0f);
            func_0040C0F0(c, W(e, 0x240) + 0xE0, 1.0f);
            func_003F1D30(e + 0x310, obj + 0x30, W(e, 0x50) + 0x30, a, b, c);
            func_00447580(e + 0x350, obj);
            Q(e, 0x370) = Q(e, 0x350);
        }
    } else {
        if (p[3] == 2) {
            func_003F2000(idx);
            func_003F1F28(idx);
        } else if (p[3] == 1) {
            func_003F2000(idx);
            Q(e, 0x350) = Q(e, 0x370);
        } else if (p[3] == 0) {
            func_003F2058(idx);
        }
    }
    *(s16 *)p = 3;
    p[2] = p[3];
    if (p[2] == 0) {
        u8 *q = p + 0x10;
        F(q, 0x10) = F(q, 0x1C);
        F(q, 0x14) = F(q, 0x18);
        W(q, 0x1C) = 0;
        Q(p, 0x40) = Q(p, 0x50);
        F(p, 0x10) = F(q, 0xC);
        W(q, 0xC) = 0;
        F(q, 4) = F(q, 8);
        Q(p, 0x30) = Q(p, 0x60);
    } else {
        u8 *q = p + 0x70;
        s32 k = W(q, 0x14) + 1;
        W(q, 0x14) = k;
        W(q, 0xC) = k;
        F(q, 0x10) = 1.0f / (float)k;
    }
}
/* localdecomp:end func_003F2090 */
