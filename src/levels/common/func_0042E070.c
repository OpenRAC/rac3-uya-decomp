#include "common.h"

extern void func_0040BBA8(void *, s32, s32);
extern void func_0042E070();

typedef struct { u8 b[0x40]; } T_39ABB0;
extern T_39ABB0 D_001D7228;
extern u8 *D_001F402C[];
void func_0042E070(u8 *out) {
    s32 acc[0x80];
    s32 tbl2[16];
    u8 *src;
    u8 *o;
    s32 i, j, k, m;
    src = D_001F402C[0];
    o = out;
    *(T_39ABB0 *)tbl2 = D_001D7228;
    for (i = 0; i < 0x200; i++) {
        if (i % 4 == 0) func_0040BBA8(acc, 0, 0x200);
        for (k = 0; k < 0x80; k += 2) {
            u8 b = *src++;
            acc[k] += tbl2[b & 0xF];
            acc[k + 1] += tbl2[b >> 4];
        }
        if (i % 4 == 3) {
            for (j = 0; j < 0x80; j++) {
                if (acc[j] < 8) acc[j] = 0;
                else acc[j] = 1 << (j % 8);
            }
            for (m = 0; m < 0x80; m += 8) {
                *o++ = (u8)acc[m] | (u8)acc[m + 1] | (u8)acc[m + 2] | (u8)acc[m + 3] | (u8)acc[m + 4] | (u8)acc[m + 5] | (u8)acc[m + 6] | (u8)acc[m + 7];
            }
        }
    }
    out[0] &= 0xFE;
}
