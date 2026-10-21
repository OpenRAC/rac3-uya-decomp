#include "common.h"

/* localdecomp:start func_00497C30 */
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;
extern Ent_00497C30 D_002EBE3C[];
extern u8 D_001426E0[];
s32 func_00497C30(s32 a0) {
    s32 i;
    s32 j;
    for (i = 1; i < 15; i++) {
        j = a0 + i;
        if (j >= 15) j -= 15;
        if (D_001426E0[D_002EBE3C[j].a]) return j;
    }
    return a0;
}
/* localdecomp:end func_00497C30 */
