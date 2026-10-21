#include "common.h"

/* localdecomp:start func_00483CD8 */
typedef struct {
    u8 pad0[56];
    u16 x38;
    u8 pad3A[182];
} Entry_00483CD8;

extern s32 D_001D8720[2];
extern u8 D_001425C0[];
extern Entry_00483CD8 D_002C5640[];
extern s32 func_00483C98(s32);
extern s32 func_005131A0(s32, s32);

void func_00483CD8(void)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        func_005131A0(func_00483C98(i), (&D_002C5640[D_001425C0[D_001D8720[i]]])->x38);
    }
}
/* localdecomp:end func_00483CD8 */
