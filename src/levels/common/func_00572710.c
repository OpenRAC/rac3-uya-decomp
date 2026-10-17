#include "common.h"

typedef struct {
    u8 pad[28];
    u8 *f1C;
} S_24B950;

extern S_24B950 *D_0024B950[];
extern u8 *func_00577EE8(s32, s32);

s32 func_00572710(s32 a) {
    u8 *o;
    u8 *p;
    s32 r;

    o = func_00577EE8(0, 33);
    r = 0;
    p = D_0024B950[0][*(s16 *)(o + 132)].f1C;
    if (a != 0) {
        if (*(s16 *)(p + 72) >= 151) {
            goto set;
        }
        goto end;
    }
    if (*(s16 *)(p + 72) < 151) {
        goto end;
    }
    if (*(s16 *)(p + 70) > 0) {
        goto end;
    }
set:
    r = 1;
end:
    return r;
}
