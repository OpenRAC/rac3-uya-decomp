#include "common.h"

/* localdecomp:start func_00305540 */
typedef int s128 __attribute__((mode(TI)));

extern u8 *D_001DC604;
extern void func_004C4AB8(s32);
extern s32 func_004C4A18(u8 *, u8 *, f32, f32, f32);

void func_00305540(u8 *a0, s128 *a1, s128 *a2, s32 a3) {
    s32 *v = *(s32 **)(a0 + 104);
    s32 n;
    if (D_001DC604 != 0) {
        u8 *e = D_001DC604 + (v[15] << 6);
        *(s128 *)e = *a1;
        *(s128 *)(e + 16) = *a2;
        if (*(s32 *)(e + 56) >= 0) {
            func_004C4AB8(*(s32 *)(e + 56));
        }
        *(s32 *)(e + 56) = func_004C4A18(a0, e, 1.0f, 1.0f, 1.0f);
        *(s32 *)(e + 48) = a3;
        *(s32 *)(e + 52) = 0;
    }
    n = v[15];
    v[18] = n;
    v[15] = n + 1;
    if (n + 1 >= 35) {
        v[15] = 0;
        v[16] = 1;
    } else if (v[16] != 1) {
        v[17]++;
    }
}
/* localdecomp:end func_00305540 */
