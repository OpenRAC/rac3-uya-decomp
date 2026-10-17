#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

extern int D_001EAA98[];

extern int func_003F8448(Vec4 *, Vec4 *, int, void *, int);

void func_00334198(u8 *moby, u8 *vars) {
    Vec4 a;
    Vec4 b;
    a = *(Vec4 *)(moby + 16);
    b = *(Vec4 *)(vars + 1024);
    a.z = a.z + 0.1f + *(f32 *)(vars + 408);
    b.z += *(f32 *)(vars + 408);
    if (!func_003F8448(&a, &b, 16, moby, 0)
        || (D_001EAA98[0] != 0 && D_001EAA98[0] == *(int *)(vars + 1088))) {
        *(Vec4 *)(vars + 1008) = *(Vec4 *)(vars + 1024);
        *(Vec4 *)(vars + 1040) = *(Vec4 *)(vars + 1024);
    }
}
