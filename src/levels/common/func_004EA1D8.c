#include "common.h"

/* localdecomp:start func_004EA1D8 */
typedef struct { u8 pad[0xAA]; s16 t; } S4EA;
s32 func_004EA1D8(S4EA *p) {
    if (p == 0) return 0;
    return p->t == 0x47;
}
/* localdecomp:end func_004EA1D8 */
