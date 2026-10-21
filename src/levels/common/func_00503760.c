#include "common.h"

/* localdecomp:start func_00503760 */
typedef struct {
    u8 pad0[0x10];
    s32 arr[1];
} S_503760;

extern S_503760 D_00142660;

void func_00503760(s32 n) {
    s32 first = D_00142660.arr[0];
    s32 last = 0;
    s32 i;
    for (i = 1; i < n; i++) {
        if (D_00142660.arr[i] != 0) {
            D_00142660.arr[i - 1] = D_00142660.arr[i];
            last = i;
        }
    }
    D_00142660.arr[last] = first;
}
/* localdecomp:end func_00503760 */
