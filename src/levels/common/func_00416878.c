#include "common.h"

typedef struct {
    s32 v[12];
} T416878;

extern T416878 D_001D6620;

s32 func_00416878(s32 x) {
    T416878 t = D_001D6620;
    s32 *p;

    if (t.v[0] != 0) {
        p = t.v;
        do {
            if (x == *p) {
                return 1;
            }
            p++;
        } while (*p != 0);
    }
    return 0;
}
