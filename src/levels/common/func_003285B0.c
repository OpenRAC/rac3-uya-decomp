#include "common.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern void func_00328588(u8 *obj, Vec4 a, Vec4 b);

void func_003285B0(u8 *obj, u8 *target, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 16) = a;
    *(Vec4 *)(obj + 240) = b;
    func_00328588(target, a, b);
}
