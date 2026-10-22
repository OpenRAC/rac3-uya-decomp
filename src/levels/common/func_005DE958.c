#include "common.h"

/* localdecomp:start func_005DE958 */
extern s32 D_0024C680[1];
extern f32 D_0024C688[2];
extern long D_0024C690[1];
extern f32 D_001D821C;
extern long func_00590438(s32, s32, f32);

void func_005DE958(s32 i, long c) {
    if (D_0024C680[i] != 0) {
        D_0024C688[i] += D_001D821C;
        if (D_0024C688[i] > 1.0f) {
            *(s32 *)&D_0024C688[i] = 0;
        }
        D_0024C690[i] = func_00590438(0x80FFFFFF, c, D_0024C688[i]);
        D_0024C680[i]--;
    } else {
        D_0024C690[i] = c;
    }
}
/* localdecomp:end func_005DE958 */
