#include "common.h"

/* localdecomp:start func_00436BD8 */
typedef struct Slot_00436BD8 {
    s16 id;
    u16 count;
    u8 state;
    u8 pad5[7];
    u8 *data;
    s32 arg;
    s32 owner;
    u8 pad18[4];
    struct Slot_00436BD8 *next;
    u8 pad20[32];
} Slot_00436BD8;

extern Slot_00436BD8 D_001F47C0[];

Slot_00436BD8 *func_00436BD8(u8 *self, s32 id, s32 arg) {
    s32 i;
    Slot_00436BD8 *e;
    u8 *d;

    for (i = 0; i < 16 && D_001F47C0[i].state != 0; i++) {
    }
    if (i == 16) {
        return 0;
    }
    e = &D_001F47C0[i];
    e->state = 2;
    e->arg = arg;
    e->id = id;
    e->owner = *(s32 *)(self + 36);
    d = (*(u8 ***)(*(u8 **)(self + 36) + 28))[(s16)id + 1];
    e->count = d[2];
    e->data = d + (d[0] + 4);
    e->next = *(Slot_00436BD8 **)(self + 80);
    *(Slot_00436BD8 **)(self + 80) = e;
    return e;
}
/* localdecomp:end func_00436BD8 */
