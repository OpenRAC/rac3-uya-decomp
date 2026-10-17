#include "common.h"
typedef struct { char pad[32]; int x; char pad2[12]; } S48;
extern S48 D_002A2EC0[];
void func_003D9828(void) {
    int i;
    for (i = 63; i >= 0; i--) {
        D_002A2EC0[i].x = 0;
    }
}
