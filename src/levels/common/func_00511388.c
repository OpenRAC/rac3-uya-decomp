#include "common.h"

typedef struct {
    u8 pad0[0xDC];
    s32 a[16];
    s32 b[16];
    u8 pad1[0x50];
    u8 c[16];
} S_3E0E48;
s32 func_00511388(void *a0, s32 a1) {
    S_3E0E48 *s = *(S_3E0E48 **)a0;
    s32 r = 0;
    if (s->a[a1] != 0 && s->c[a1] == 0) {
        s->b[a1] = 0;
        (*(S_3E0E48 **)a0)->c[a1] = 1;
        r = 1;
    }
    return r;
}
