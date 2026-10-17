#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_004452B0(s32, s32);
extern void func_00375B60(u8 *, u8 *, void *, void *, s32);
extern void func_00448A30(u8 *);

u8 *func_003B9558(u8 *parent)
{
    u8 *obj = func_004452B0(6449, 128);

    if (obj != 0) {
        u8 *vars = *(u8 **)(obj + 104);

        *(s32 *)(vars + 8) = 0;
        *(u8 **)(obj + 184) = parent;
        obj[48] = parent[48];
        *(u16 *)(obj + 50) = *(u16 *)(parent + 50);
        obj[49] = parent[49];
        obj[32] = 1;
        *(long *)(obj + 56) = *(long *)(parent + 56);
        *(u128_t *)(obj + 16) = *(u128_t *)(parent + 16);
        func_00375B60(obj, vars, vars + 4, vars + 16, 0);
        func_00448A30(obj);
    }
    return obj;
}
