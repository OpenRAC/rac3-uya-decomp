#include "common.h"

extern u8 *D_001DFA1C[];

extern void func_004405E0(void *, int);
extern void func_0042FC00(int, int);

void func_003AC160(u8 *moby) {
    int *vars = *(int **)(moby + 104);
    int i;
    func_004405E0(moby, 1);
    for (i = 0; i < 2; i++) {
        if (vars[i + 2] != -1) {
            func_004405E0(D_001DFA1C[0] + vars[i + 2] * 256, 1);
        }
        if (moby[33] != 255) {
            func_0042FC00(moby[33], 1);
        }
    }
}
