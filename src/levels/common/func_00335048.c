#include "common.h"

/* localdecomp:start func_00335048 */
typedef void (*Fn_335048)(void *, s32, s32);

extern s32 func_00458AE0(void *, s32);
extern s32 func_00334B28(void *, u8 *, void *, u8 *, void *, u8 *);
extern void func_00455C88(void *, u8 *, s32, s32);
extern void func_00457440(void *, u8 *);

s32 func_00335048(void *a0, u8 *a1, void *a2, u8 *a3, void *t0, u8 *t1, u8 *t2) {
    if (*(s32 *)(t1 + 108) != -1 && t1[153] == 0 && a1[94] == 0) {
        if (func_00458AE0(a2, *(s32 *)(t1 + 108)) == 0) {
            goto end;
        }
        func_00334B28(a0, a1, a2, a3, t0, t1);
        a1[94] = 1;
        goto end;
    }
    if (t1[16] != 2 && t1[17] != 2) {
        if (*(s32 *)(t1 + 100) != -1 || *(s32 *)(t1 + 96) != -1) {
            func_00455C88(a2, a3 + 1008, 0, 0);
            func_00457440(a2, a3 + 1008);
        }
    }
end:
    if (t1[151] == 0) {
        (*(Fn_335048 *)(t2 + 36))(a2, 0, 10);
    } else {
        (*(Fn_335048 *)(t2 + 32))(a2, 0, 10);
    }
    return 0;
}
/* localdecomp:end func_00335048 */
