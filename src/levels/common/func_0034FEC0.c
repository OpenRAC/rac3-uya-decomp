#include "common.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 m[4];
} Mtx4;

extern void func_0041ACC0(void *, s32, Mtx4 *);
extern void func_003F1490(void *, Mtx4 *);
extern void func_0042AE20(void *, void *);
extern f32 func_003F1A98(f32, f32);
extern void func_003F1208(void *, void *);

void func_0034FEC0(void *arg0, u8 *arg1) {
    Mtx4 m;

    func_0041ACC0(arg0, 0, &m);
    *(Vec4 *)(*(u8 **)(arg1 + 608) + 16) = m.m[3];
    func_003F1490(*(u8 **)(arg1 + 608) + 192, &m);
    func_0042AE20(*(u8 **)(arg1 + 608) + 192, *(u8 **)(arg1 + 608) + 240);
    if (*(f32 *)(arg1 + 880) != 0.0f) {
        *(f32 *)(*(u8 **)(arg1 + 608) + 248) = func_003F1A98(*(f32 *)(*(u8 **)(arg1 + 608) + 248), *(f32 *)(arg1 + 880));
        func_003F1208(*(u8 **)(arg1 + 608) + 192, *(u8 **)(arg1 + 608) + 240);
    }
}
