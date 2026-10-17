#include "common.h"
typedef struct {
    s32 key;
    s32 val;
} Pair_00417670;
extern Pair_00417670 D_002D1580[];
s32 func_00417670(s32 a0) {
    s32 i;
    for (i = 0; D_002D1580[i].key != 0; i++) {
        if (a0 == D_002D1580[i].key) {
            return 1;
        }
    }
    return 0;
}
