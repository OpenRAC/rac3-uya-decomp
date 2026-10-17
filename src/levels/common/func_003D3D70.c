#include "common.h"
extern int D_001DEFEC;
extern float D_002BB5F0[];
float func_003D3D70(void) {
    D_001DEFEC = (D_001DEFEC + 1) % 44;
    return D_002BB5F0[D_001DEFEC];
}
