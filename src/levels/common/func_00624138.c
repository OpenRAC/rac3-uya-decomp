#include "common.h"

extern void func_0062FB70(void *, void *, void *, f32);
extern void func_0062FAE0(void *, void *, void *, f32);
extern void func_0062FA50(void *, void *, void *, f32);
extern void func_0062FD10(void *, void *, void *, f32);

void func_00624138(void *arg0, void *arg1, s32 arg2, f32 arg3, f32 arg4)
{
    if (arg2 != 0) {
        func_0062FB70(arg0, arg1, arg1, arg3);
        func_0062FAE0(arg0, arg1, arg1, arg4);
    } else {
        func_0062FA50(arg0, arg1, arg1, arg3);
        func_0062FD10(arg0, arg1, arg1, arg4);
    }
}
