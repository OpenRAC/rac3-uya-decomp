#include "common.h"

extern s32 D_001E1DF0;
extern u8 D_002B3B40[];
extern f32 func_0040CEC8(f32, f32);
extern void func_00409448(void *, void *);

void func_0037D518(u8 *obj) {
    u8 *p = *(u8 **)(obj + 104);
    *(f32 *)(p + 48) = func_0040CEC8(*(f32 *)(p + 48), 0.017453292f);
    func_00409448(&D_001E1DF0, D_002B3B40);
}
