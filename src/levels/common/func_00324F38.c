#include "common.h"

/* localdecomp:start func_00324F38 */
typedef struct {
    u8 pad0[0x120];
    s32 x120[16];
    s32 x160[16];
    u8 pad1[0x140];
    u16 x2E0[16];
    u8 x300[16][3];
} S_324F38;

extern s32 func_00438488(s32, s32, s32);
extern s32 func_00445F18(void *);
extern u8 *func_00440728(void *);

s32 func_00324F38(void *a, S_324F38 *b, u8 *c) {
    s32 i;
    s32 r;
    u8 *q;

    for (i = 0; b->x120[i] != -1 && i < 16; i++) {
        if (*(s16 *)(c + 0xAA) == b->x120[i]) {
            return i;
        }
    }
    if (i == 16) {
        return -1;
    }
    r = func_00438488(*(s16 *)(c + 0xAA), 1, 28);
    b->x160[i] = r;
    if (r == 0 || func_00445F18(c) == 0) {
        return -1;
    }
    b->x120[i] = *(s16 *)(c + 0xAA);
    q = func_00440728(c);
    if (q != 0) {
        b->x2E0[i] = *(u16 *)(q + 4);
        b->x300[i][0] = q[20];
        b->x300[i][1] = q[21];
        b->x300[i][2] = q[22];
    } else {
        b->x2E0[i] = 0;
        b->x300[i][0] = 0;
        b->x300[i][1] = 0;
        b->x300[i][2] = 0;
    }
    return i;
}
/* localdecomp:end func_00324F38 */
