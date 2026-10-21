#include "common.h"

/* localdecomp:start func_00451078 */
extern s32 D_001D673C;
extern void func_00445F50(void *a0, void *a1, s32 a2);
extern void func_00446E68(void *a0, void *a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 s0, f32 f12);
extern void func_00446A00(void *a0, void *a1, s32 a2, s32 a3, s32 t0, s32 t1);
extern void func_00446480(void *a0, void *a1, s32 a2);
extern s32 func_00451430(void *a0, u8 *a1);
extern s32 func_00452258(void *a0, u8 *a1);

s32 func_00451078(void *a0, u8 *a1) {
    s32 ret = 0;
    if (a1[24] == 1 && a1[25] != 0) {
        func_00445F50(a0, a1 + 128, a1[25]);
    }
    if (a1[24] == 2 && a1[25] != 0) {
        func_00446E68(a0, a1 + 128, a1[25], 0x4F804020, 10, 16, 94, 0, 0, 1.2f);
    }
    if (a1[24] == 3 && a1[25] != 0) {
        func_00446A00(a0, a1 + 128, a1[25], 0x4F804020, 2, 3);
    }
    if (a1[24] == 4 && a1[25] != 0) {
        func_00446480(a0, a1 + 128, a1[25]);
    }
    switch (a1[26]) {
    case 0:
    case 1:
    case 2:
        if (D_001D673C == 0) {
            ret = func_00451430(a0, a1);
        } else {
            ret = func_00452258(a0, a1);
        }
        break;
    }
    if (ret & 2) {
        a1[24] = 0;
    }
    return ret;
}
/* localdecomp:end func_00451078 */
