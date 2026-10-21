#include "common.h"

/* localdecomp:start func_004C4710 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Unk24FA60;
extern Unk24FA60 D_0024FA60[];
s32 func_004C4710(s32 b, s32 a) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_0024FA60[i].b == b && D_0024FA60[i].a == a) {
            return D_0024FA60[i].c;
        }
    }
    return -1;
}
/* localdecomp:end func_004C4710 */
