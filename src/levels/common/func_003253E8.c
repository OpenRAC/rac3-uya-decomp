#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern s32 func_00438488(s32 a0, s32 a1, s32 a2);
extern u8 *func_00445F18(u8 *a0);
extern void func_0040C638(u8 *a0, u8 *a1);
extern void func_003B5048(s32 a0, u8 *a1, s32 a2);
extern void func_00439610(u8 *a0);
void func_003253E8(s32 a0, u8 *a1) {
    u8 *m;
    u8 *n;
    u8 *p;
    u8 *c;
    if (func_00438488(500, 1, 28) != 0) {
        m = *(u8 **)(a1 + 108);
        while (m != 0) {
            n = func_00445F18(m);
            p = *(u8 **)(m + 104);
            *(u128_t *)(m + 16) = *(u128_t *)(p + 256);
            *(u128_t *)(m + 240) = *(u128_t *)(p + 272);
            func_0040C638(m + 192, m + 240);
            func_003B5048(0, m, 0);
            *(u16 *)(m + 52) &= 0xFFBE;
            c = *(u8 **)(m + 36);
            *(u16 *)(m + 52) |= *(u16 *)(c + 68) & 0x1000;
            *(s32 *)(m + 152) = *(s32 *)(c + 16);
            func_00439610(m);
            m = *(u8 **)(n + 4);
        }
    }
}
