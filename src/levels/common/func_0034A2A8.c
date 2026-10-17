#include "common.h"
typedef struct {
    u8 pad[32];
    u8 type;
    u8 pad2[223];
} E_0034A2A8;
extern E_0034A2A8 *D_001DFA1C;
s32 func_0034A2A8(u8 *a0, s32 a1) {
    s32 *q = (s32 *)(*(u8 **)(a0 + 104) + 16);
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (q[i] != -1) {
            u8 t = D_001DFA1C[q[i]].type;
            if (t != 3 && (a1 == 0 || t != 2)) {
                count++;
            }
        }
    }
    return count;
}
