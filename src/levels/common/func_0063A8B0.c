#include "common.h"

typedef struct { s32 f0; u8 p4[0x18]; } S_63A8B0;
extern u8 D_004998A0[];
extern S_63A8B0 D_00484160[];
extern void func_0058EFB8(s16 *);
extern u32 func_005C0F88(s32);
extern u32 func_005C1030(s32);
extern void func_00674710(u8);

void func_0063A8B0(u8 *self) {
    union { u8 b[8]; u32 w[2]; } buf;
    u8 *s;
    s32 i;
    u32 val;
    s32 ok;

    func_0058EFB8((s16 *)(self + 0x24A6));
    func_0058EFB8((s16 *)(self + 0x24A8));
    s = self + 0x19E4;
    val = 0;
    if (*(volatile u8 *)s != 0) {
        u32 len = self[0x19E4];
        u8 *d = buf.b;
        s32 n = len + 1;
        s32 off = ((u32)s - len) & 7;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_004998A0[n + ((off + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)s;
        buf.w[1] ^= buf.w[0];
        val = buf.w[1];
    }
    ok = val != 0x37;
    if (!ok) return;
    if (*(s32 *)(self + 0x251C) != 0) return;
    if (self[0x1A0C] != 0) return;
    if (D_00484160[*(s32 *)(self + 0x2544)].f0 != 0) return;
    if (func_005C0F88(*(s32 *)(self + 0x2534)) & 0x10) {
        *(s16 *)(self + 0x24A6) = 20;
    }
    if (*(s16 *)(self + 0x24A6) == 0) return;
    if (!(func_005C1030(*(s32 *)(self + 0x2534)) & 0x10)) return;
    self[0x24AA] = 1;
    func_00674710(self[0x24C9]);
    if (*(s16 *)(self + 0x24A8) != 0) return;
    *(s16 *)(self + 0x24A8) = 20;
}
