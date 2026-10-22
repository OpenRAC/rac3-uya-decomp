#include "common.h"

/* localdecomp:start func_004B7010 */
typedef struct {
    u8 active;
    s8 b1;
    s8 b2;
    s8 b3;
    u16 id;
    u8 pad6[2];
    s32 w8;
    s32 wC;
    u32 w10;
    s32 w14;
    s32 w18;
    u8 pad1C[0x44];
} S_4B7010;

extern S_4B7010 D_002393F0[];
extern u16 D_001D96E6;

static __inline__ void init_4B7010(S_4B7010 *p) {
    p->b1 = -1;
    p->b2 = -1;
    p->b3 = -1;
    p->id = 0xFFFF;
    p->wC = 0;
    p->w8 = 0;
    p->w10 = 0xFFFFFFFF;
    p->w14 = 0;
    p->w18 = -1;
}

S_4B7010 *func_004B7010(void) {
    u16 i;
    S_4B7010 *q;

    for (i = 0; D_002393F0[i].active != 0 && i < 12; i++) {
    }
    if (i == 12) {
        return 0;
    }
    init_4B7010(&D_002393F0[i]);
    q = &D_002393F0[i];
    q->id = D_001D96E6++;
    q->active = 1;
    return q;
}
/* localdecomp:end func_004B7010 */
