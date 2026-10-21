#include "common.h"

/* localdecomp:start func_00474428 */
typedef struct {
    s32 n;
    f32 y, z, w;
} V_474428;
extern V_474428 *D_0021F740[];
extern f32 func_0040BFE8(V_474428 *, V_474428 *);
s32 func_00474428(s32 ia, s32 ib, s32 *o1, s32 *o2) {
    V_474428 *a = D_0021F740[ia];
    V_474428 *b = D_0021F740[ib];
    s32 j, i, pi, pj;
    for (i = 0; i < a->n - 1; i++) {
        for (j = 0; j < b->n - 1; j++) {
            if (func_0040BFE8((V_474428 *)((u8 *)a + 16 + ((i) << 4)), (V_474428 *)((u8 *)b + 16 + ((j) << 4))) < 0.5f) {
                pi = i != 0 ? i - 1 : a->n - 2;
                pj = j != 0 ? j - 1 : b->n - 2;
                if (func_0040BFE8((V_474428 *)((u8 *)a + 16 + ((i + 1) << 4)), (V_474428 *)((u8 *)b + 16 + ((j + 1) << 4))) < 0.5f) {
                    *o1 = i;
                    *o2 = j;
                    return 1;
                }
                if (func_0040BFE8((V_474428 *)((u8 *)a + 16 + ((pi) << 4)), (V_474428 *)((u8 *)b + 16 + ((j + 1) << 4))) < 0.5f) {
                    *o1 = pi;
                    *o2 = j;
                    return 1;
                }
                if (func_0040BFE8((V_474428 *)((u8 *)a + 16 + ((i + 1) << 4)), (V_474428 *)((u8 *)b + 16 + ((pj) << 4))) < 0.5f) {
                    *o1 = i;
                    *o2 = pj;
                    return 1;
                }
                if (func_0040BFE8((V_474428 *)((u8 *)a + 16 + ((pi) << 4)), (V_474428 *)((u8 *)b + 16 + ((pj) << 4))) < 0.5f) {
                    *o1 = pi;
                    *o2 = pj;
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_00474428 */
