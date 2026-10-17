#include "common.h"

extern u8 D_001A4C60[];
extern s32 D_001DDB20;

extern int func_00412918(void *, int, int);
extern void func_003571D8(int, int);

void func_00358540(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    int i;
    int *p = (int *)(vars + 160);
    for (i = 0; i < 4; i++, p++) {
        int id = p[-24];
        if (id != -1 && func_00412918(D_001A4C60, id, 0)) {
            D_001DDB20 = *p;
        }
    }
    if (func_00412918(D_001A4C60, *(int *)(vars + 88), 0)) {
        func_003571D8(3173, 80);
    }
}
