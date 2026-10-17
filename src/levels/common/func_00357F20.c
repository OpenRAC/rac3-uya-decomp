#include "common.h"
void func_00357F20(f32 *m, s32 a1, f32 a, f32 b, f32 c, f32 d, f32 e) {
    s32 i;
    if (a1 != 0) {
        m[20] = a;
        m[22] = b;
        m[21] = c;
        m[25] = d;
        m[24] = a;
        m[26] = b;
        m[23] = c;
        m[27] = d;
        return;
    }
    for (i = 3; i >= 0; i--) {
        m[i * 4 + 1] = e;
    }
    m[0] = a;
    m[4] = b;
    m[2] = c;
    m[10] = d;
    m[8] = a;
    m[12] = b;
    m[6] = c;
    m[14] = d;
}
