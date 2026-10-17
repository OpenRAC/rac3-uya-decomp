#include "common.h"

extern s32 D_001DF9C0;

void func_00359588(s32 *a, s32 *b) {
    if (a[8] != 1) {
        if (a[8] == 2) {
            a[9] = 0;
        } else {
            a[9] = D_001DF9C0;
        }
        a[8] = 1;
    }
    b[1] = D_001DF9C0;
}
