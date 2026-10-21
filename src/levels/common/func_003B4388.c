#include "common.h"

typedef struct {
    u8 p0[0x38];
    f32 f38;
    s32 f3C;
    u8 p40[0x48];
    s32 f88;
    s32 f8C;
    u8 p90[0x2C];
    s32 fBC;
    s32 fC0;
    s32 fC4;
} S_003B4388;
typedef struct {
    u8 p0[0x68];
    S_003B4388 *f68;
} O_003B4388;
/* localdecomp:start func_003B4388 */
s32 func_003B4388(O_003B4388 *a) {
    S_003B4388 *p = a->f68;
    s32 bc;
    s32 q;
    f32 r;
    if (p->f3C != 0 && p->f3C <= p->fC4)
        return 1;
    bc = p->fBC;
    q = p->f88;
    if (bc < 0) {
        if (q != 0) {
            if (p->f8C >= q) {
                r = (f32)p->fC4 / (f32)p->fC0;
                if (p->f38 <= r)
                    return 1;
            }
            return 0;
        }
        if (p->f3C == 0)
            return 1;
    }
    if (q != 0 && p->f8C >= q)
        r = (f32)p->fC4 / (f32)p->fC0;
    else
        r = (f32)p->fC4 / (f32)bc;
    return p->f38 <= r;
}
/* localdecomp:end func_003B4388 */
