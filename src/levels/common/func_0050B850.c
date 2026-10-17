#include "common.h"

typedef struct {
    s16 key;
    s16 val;
} S_50B850;

extern S_50B850 *D_001A73E4[];

s32 func_0050B850(s32 key, s32 *out) {
    S_50B850 *p = D_001A73E4[0];
    s32 i;
    if (p == 0) {
        return 0;
    }
    for (i = 0; p[i].key != -1; i++) {
        if (key == p[i].key) {
            *out = p[i].val;
            return 1;
        }
    }
    *out = 0;
    return 0;
}
