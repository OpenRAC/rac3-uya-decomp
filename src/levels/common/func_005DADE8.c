#include "common.h"
extern u8 *D_0024C05C;
extern float func_005DADC8(void *);
float func_005DADE8(s32 a0) {
    float r = 0.0f;
    if (a0 >= 0) r = func_005DADC8(D_0024C05C + (a0 << 8));
    return r;
}
