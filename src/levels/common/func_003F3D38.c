#include "common.h"
extern int D_001DF940[];
void func_003F3D38(int v) {
    int *p = D_001DF940;
    int i;
    for (i = 15; i >= 0; i--) {
        if (*p == v) {
            *p = 0;
        }
        p++;
    }
}
