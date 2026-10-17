#include "common.h"
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;
extern u8 D_001E9620[];
extern s32 func_00409388(void *, Vec4 *, s32, s32, s32);
extern void func_00452A60(Vec4 *, void *, void *, void *);
extern float func_0041C8F0(void *, Vec4 *);
s32 func_00359618(void *a, Vec4 *pos, void *b) {
    Vec4 tmp;
    if (func_00409388(a, pos, 2, 0, 0)) {
        func_00452A60(&tmp, a, D_001E9620, b);
    } else {
        tmp = *pos;
    }
    if (func_0041C8F0(b, &tmp) > 0.16000001f) return 0;
    return 1;
}
