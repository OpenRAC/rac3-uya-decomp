#include "common.h"

/* localdecomp:start func_006197F0 */
typedef struct {
    u8 pad[0x24C9];
    u8 id;
    u8 pad2[0x4500 - 0x24CA];
} S_006197F0;
extern s32 *D_002412A0[2];
extern S_006197F0 D_002FB100[];

s32 func_006197F0(S_006197F0 *a0) {
    s32 i;
    s32 *cnt = D_002412A0[0];
    for (i = 0; i < *cnt; i++) {
        if (a0 == &D_002FB100[i]) {
            return a0->id;
        }
    }
    return -1;
}
/* localdecomp:end func_006197F0 */
