#include "common.h"

/* localdecomp:start func_004C8D90 */
extern s32 func_0051DC38();
extern void func_004C9BE0();
extern s32 D_001DB278[];

extern void func_004C9BE0();
extern s32 func_0051DC38();
extern s32 D_001DB278[];
void func_004C8D90(u8 *p, s32 f) {
    *(s32 **)(p + 0x24) = D_001DB278;
    if (*(s32 *)(p + 0x20) != 0) {
        if (p[0x14] == 0) func_004C9BE0(*(s32 *)(p + 0x20), *(s32 *)(p + 0));
        if (p[0x16] == 0) func_004C9BE0(*(s32 *)(p + 0x20), *(s32 *)(p + 8));
        if (p[0x15] == 0) func_004C9BE0(*(s32 *)(p + 0x20), *(s32 *)(p + 4));
        if (p[0x17] == 0) func_004C9BE0(*(s32 *)(p + 0x20), *(s32 *)(p + 0xC));
    }
    if (f & 1) func_0051DC38(p);
}
/* localdecomp:end func_004C8D90 */
