#include "common.h"

/* localdecomp:start func_00335720 */
typedef void (*Func00335720Cb)(void *, s32, s32);

extern s32 func_00440878(s32, s32);
extern s32 func_0040BA90(void *);

s32 func_00335720(u8 *arg0, u8 *arg1, void *arg2, s32 arg3, u8 *arg4, u8 *arg5) {
    Func00335720Cb cb;
    u8 state;

    state = arg0[188];
    if (state == 0) {
        cb = *(Func00335720Cb *)(arg5 + 92);
        if (cb != 0) {
            cb(arg2, 1, 10);
        }
        if (arg1[93] != 0) {
            arg0[188] = 1;
            *(s32 *)(arg1 + 96) = func_00440878(120, 240);
        }
    } else if (state == 1) {
        cb = *(Func00335720Cb *)(arg5 + 96);
        if (cb != 0) {
            cb(arg2, 0, 3);
        }
        if ((arg4[22] != 2 && func_0040BA90(arg1 + 96) != 0) ||
            ((s8)arg1[92] != -1 && func_0040BA90(arg1 + 124) != 0)) {
            arg0[188] = 2;
        }
    } else if (state == 2) {
        cb = *(Func00335720Cb *)(arg5 + 100);
        if (cb != 0) {
            cb(arg2, 1, 3);
        }
        if (arg1[93] != 0) {
            arg0[188] = 3;
            *(s32 *)(arg1 + 96) = func_00440878(60, 150);
        }
    } else if (state == 3) {
        cb = *(Func00335720Cb *)(arg5 + 104);
        if (cb != 0) {
            cb(arg2, 1, 3);
        }
        if (func_0040BA90(arg1 + 96) != 0 && arg1[93] != 0) {
            arg0[188] = 0;
        }
    }
    return 0;
}
/* localdecomp:end func_00335720 */
