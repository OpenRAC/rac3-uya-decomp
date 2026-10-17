#include "common.h"
extern s32 D_0024D590[];
extern s32 D_0024D550[];
extern s32 D_001E1D00;
void func_0051DE40(s32 a0) {
    s32 n = D_0024D590[0];
    s32 i = 0;
    s32 *p = D_0024D550;
    do {
        if (*p == a0) {
            *p = 0;
            n--;
            break;
        }
        i++;
        p++;
    } while (i < 16);
    D_001E1D00 = n;
}
