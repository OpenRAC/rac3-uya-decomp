#include "common.h"

/* localdecomp:start func_004179E8 */
typedef struct {
    u8 pad0[8];
    u8 buf[80];
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[4];
    s32 f68;
    u8 f6C;
} S_4179E8;

extern void *func_0011A264(void *, s32, s32);

void *func_004179E8(S_4179E8 *a) {
    void *r;
    a->f58 = 0;
    a->f5C = 0;
    a->f60 = 0;
    r = func_0011A264(a->buf, 205, 80);
    a->f6C = 0;
    a->f68 = 1;
    return r;
}
/* localdecomp:end func_004179E8 */
