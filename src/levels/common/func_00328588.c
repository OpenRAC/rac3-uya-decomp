#include "common.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

void func_00328588(u8 *obj, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 432) = a;
    *(Vec4 *)(obj + 448) = b;
}
