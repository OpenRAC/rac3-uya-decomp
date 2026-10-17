#include "common.h"
typedef struct {
    f32 m[16];
} M_0050D430;
typedef struct {
    f32 v[4];
} V_0050D430;
extern u8 D_001A4BE0[];
extern f32 func_0040BF68(V_0050D430 *);
extern void func_0040C658(M_0050D430 *, u8 *);
extern void func_0040C8E0(M_0050D430 *, M_0050D430 *);
extern void func_0040C2F8(V_0050D430 *, V_0050D430 *, M_0050D430 *);
f32 func_0050D430(V_0050D430 *a0) {
    u8 *g = D_001A4BE0;
    M_0050D430 m0, m1;
    V_0050D430 v;
    switch (g[9716]) {
    case 0:
        return func_0040BF68(a0);
    case 1:
    case 2:
        func_0040C658(&m0, *(u8 **)(g + 9664) + 240);
        func_0040C8E0(&m1, &m0);
        func_0040C2F8(&v, a0, &m1);
        return func_0040BF68(&v);
    }
    return 0.0f;
}
