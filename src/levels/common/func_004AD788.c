#include "common.h"

/* localdecomp:start func_004AD788 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Ent_4AD788;

extern Ent_4AD788 D_0023B360[];

s32 func_004AD788(u32 a0) {
    if (a0 >= 64) {
        return -3;
    }
    return D_0023B360[a0].b;
}
/* localdecomp:end func_004AD788 */
