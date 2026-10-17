#include "common.h"

extern s32 D_001A5F78[];
extern s32 *func_0053EB80(void);
extern s32 func_0053EB48(s32, s32, s32, s32, s32 *);

s32 func_0053D1A8(s32 id, s32 n, s32 *src) {
    s32 *buf;
    s32 *dst;
    s32 i;

    if (n < 0 || (buf = func_0053EB80()) == 0) {
        return -1;
    }
    dst = (s32 *)((char *)buf + func_0053EB48(3, id, D_001A5F78[0], n, buf));
    for (i = 0; i < n; i++) {
        *dst++ = src[i];
    }
    *buf = (char *)dst - (char *)buf;
    return id;
}
