#include "common.h"
typedef struct {
    s32 key;
    s32 val;
} E_4BD328;
extern E_4BD328 D_001DAE40;
extern s32 D_001DAE44[];
extern E_4BD328 D_001DB020[];
s32 func_004BD328(s32 a0) {
    E_4BD328 *p;
    s32 *q;
    if (D_001DAE40.key >= 0) {
        p = &D_001DAE40;
        q = D_001DAE44;
        do {
            if (a0 == p->key) {
                return *q;
            }
            p++;
            q += 2;
        } while ((p->key >= 0) & ((s32)p < (s32)D_001DB020));
    }
    return -1;
}
