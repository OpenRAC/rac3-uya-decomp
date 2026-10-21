#include "common.h"

/* localdecomp:start func_00328B90 */
typedef struct {
    u8 pad[0xC];
    s32 f;
    s32 g;
    u8 pad2[0x24];
} E_002AEA90;
typedef struct {
    u8 pad[8];
    s32 a;
    s32 b;
    u8 pad2[0x43];
    u8 idx;
} O_00328B90;
extern E_002AEA90 D_002AEA90[];
s32 func_00328B90(O_00328B90 **p) {
    O_00328B90 *o = p[0x68 / 4];
    if (o->a != -1) return 1;
    if (o->idx == 0xFF) return 0;
    return ((E_002AEA90 *)((u8 *)D_002AEA90 + o->idx * 56))->f != 0;
}
/* localdecomp:end func_00328B90 */
