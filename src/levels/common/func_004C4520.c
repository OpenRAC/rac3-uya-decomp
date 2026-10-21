#include "common.h"

/* localdecomp:start func_004C4520 */
typedef struct {
    u8 pad[80];
} Ent_4C4520;

extern Ent_4C4520 D_0024E660[];

Ent_4C4520 *func_004C4520(u32 a0) {
    Ent_4C4520 *r = 0;
    if (a0 < 64) {
        r = &D_0024E660[a0];
    }
    return r;
}
/* localdecomp:end func_004C4520 */
