#include "common.h"

typedef struct {
    u8 pad0[28];
    u8 *owner;
    u8 pad20[56];
    s32 flags;
    u8 pad5C[36];
} Entry_004A6DF8;

extern Entry_004A6DF8 D_001A3170[];
extern void func_004A6E88(s32);

void func_004A6DF8(u8 *obj, s32 check)
{
    s32 i;
    Entry_004A6DF8 *e;

    if (obj == 0) {
        return;
    }
    e = D_001A3170;
    for (i = 0; i < 52; i++, e++) {
        if (obj == e->owner) {
            if (check == 0 || (e->flags & 4)) {
                func_004A6E88(i);
            }
        }
    }
    obj[109] = 255;
}
