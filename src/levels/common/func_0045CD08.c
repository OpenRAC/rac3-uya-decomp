#include "common.h"

/* localdecomp:start func_0045CD08 */
extern void func_0045CD08();
extern s16 D_001CCFFC[];

typedef struct { s32 x0; s16 pad4; s16 pad6; s16 pad8; s16 hA; s16 padC; s16 padE; s16 h10; } S_39D970;
extern s16 D_001CCFFC[];
void func_0045CD08(s32 a, long b) {
    S_39D970 *p = (S_39D970 *)(s32)b;
    if (p) {
        if (a < 0) p->x0 = a;
        if (a != 0) {
            if (p->hA == 9) {
                p->hA = 4;
                if (p->h10) D_001CCFFC[0] = 1;
            }
        } else {
            p->hA = 0;
        }
    }
}
/* localdecomp:end func_0045CD08 */
