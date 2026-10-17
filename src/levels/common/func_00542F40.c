#include "common.h"

extern s32 D_001DF720;
extern void func_00544C08(u8 *a);
extern void func_00544798(u8 *a);
extern void func_00668148(int a, u8 *b, int c, void *d);

void func_00542F40(u8 *a0)
{
    int v = *(int *)(*(u8 **)(a0 + 104) + 900);
    func_00544C08(a0);
    func_00544798(a0);
    func_00668148(v, a0, 6, &D_001DF720);
}
