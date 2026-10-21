#include "common.h"

/* localdecomp:start func_00483178 */
typedef struct {
    u8 pad[8];
    s32 f8;
    u8 pad2[0xE4];
} S_002C5640;
extern u8 D_001425C0[];
extern S_002C5640 D_002C5640[];
extern s32 func_004821D8(void);
extern s32 func_0047A310(s32);
s32 func_00483178(void) {
    s32 i = func_004821D8();
    S_002C5640 *e = (S_002C5640 *)((u8 *)D_002C5640 + D_001425C0[i] * 0xF0);
    return func_0047A310(e->f8) == i;
}
/* localdecomp:end func_00483178 */
