#include "common.h"

typedef struct {
    s32 cur;
    u8 pad4[8];
    s32 count;
} Struct_001F3FC0;

extern Struct_001F3FC0 D_001F3FC0;
extern u8 D_001F3FE0[][16];
extern s32 func_0040D088(s32, void *, void *);

s32 func_00448E90(s32 a0)
{
    s32 i;
    s32 r = 0;

    for (i = D_001F3FC0.count - 1; i >= 0; i--) {
        if (func_0040D088(a0, D_001F3FE0[i], D_001F3FE0[i + 2])) {
            r = i + 1;
            break;
        }
    }
    return r == D_001F3FC0.cur;
}
