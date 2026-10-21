#include "common.h"

/* localdecomp:start func_004D0890 */
typedef struct { s32 f0; s32 f4; s32 f8; } S_ABF88;
s32 func_004D0890(S_ABF88 *p, s32 a1) {
    s32 t = p->f8 * 0x10 + 0x10;
    s32 addr = (p->f4 + t) & 0xFFFFFFF;
    if (a1 == addr) {
        return 0;
    }
    return (u32)(a1 - p->f0) >> 11;
}
/* localdecomp:end func_004D0890 */
