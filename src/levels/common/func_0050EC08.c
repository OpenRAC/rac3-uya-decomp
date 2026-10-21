#include "common.h"

/* localdecomp:start func_0050EC08 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_004E1518(s32);
extern void func_0040C8C0(void *, void *);
extern void func_004397B0(void *);
extern void func_004E1758(void *, void *, s32, s32, s32);
extern u8 D_001A5940[];
extern u8 D_00251700[];
extern u8 D_00251900[];
extern u8 D_00251A00[];
extern u8 D_001DBDA0[];
extern u8 D_001DBDB0[];
extern u8 D_001DBDC8[];

void func_0050EC08(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *tbl;

    func_004E1518(arg0);
    tbl = D_001A5940;
    *(u128_t *)(arg1 + 16) = *(u128_t *)tbl;
    func_0040C8C0(arg1 + 192, tbl - 48);
    func_004397B0(arg1);
    func_004E1758(D_001DBDA0, D_00251700, *(s32 *)(arg1 + 36), 0, arg0);
    *(u8 **)(arg1 + 88) = D_00251700;
    *(s32 *)(arg1 + 68) = 0;
    *(u8 **)(arg1 + 92) = D_00251700;
    *(s32 *)(arg1 + 64) = 0;
    if (arg2 != 0) {
        *(u128_t *)(arg2 + 16) = *(u128_t *)(tbl - 128);
        func_0040C8C0(arg2 + 192, tbl - 176);
        func_004397B0(arg2);
        func_004E1758(D_001DBDB0, D_00251900, *(s32 *)(arg2 + 36), 0, arg0);
        *(u8 **)(arg2 + 88) = D_00251900;
        *(s32 *)(arg2 + 68) = 0;
        *(u8 **)(arg2 + 92) = D_00251900;
        *(s32 *)(arg2 + 64) = 0;
    }
    if (arg3 != 0) {
        *(u128_t *)(arg3 + 16) = *(u128_t *)(tbl - 64);
        func_0040C8C0(arg3 + 192, tbl - 112);
        func_004397B0(arg3);
        func_004E1758(D_001DBDC8, D_00251A00, *(s32 *)(arg3 + 36), 0, arg0);
        *(u8 **)(arg3 + 88) = D_00251A00;
        *(s32 *)(arg3 + 68) = 0;
        *(u8 **)(arg3 + 92) = D_00251A00;
        *(s32 *)(arg3 + 64) = 0;
    }
}
/* localdecomp:end func_0050EC08 */
