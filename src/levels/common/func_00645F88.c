#include "common.h"

typedef struct Obj00645F88 Obj00645F88;
typedef struct {
    u8 pad[28];
    s32 (*fn)(Obj00645F88 *, s32);
} VT00645F88;
struct Obj00645F88 {
    u8 pad[20];
    VT00645F88 *vt;
};

extern s32 func_005B6970(u8 *);

s32 func_00645F88(u8 *o, Obj00645F88 *b) {
    if (*(s16 *)(o + 170) == 4253) {
        if (b->vt->fn(b, -1)) {
            return 1;
        }
    }
    return func_005B6970(o) != 0;
}
