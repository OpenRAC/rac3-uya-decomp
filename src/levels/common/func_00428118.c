#include "common.h"

typedef struct {
    s32 cur;
    u8 pad4[8];
    s32 count;
    u8 pad10[16];
    u8 entries[1][16];
} Struct_001F3FC0;

extern Struct_001F3FC0 D_001F3FC0;
extern s32 func_0040D088(s32, void *, void *);

s32 func_00428118(s32 a0)
{
    s32 i;

    for (i = D_001F3FC0.count - 1; i >= 0; i--) {
        if (func_0040D088(a0, D_001F3FC0.entries[i], D_001F3FC0.entries[i + 2])) {
            return i + 1;
        }
    }
    return 0;
}
