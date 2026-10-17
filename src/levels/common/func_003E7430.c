#include "common.h"
typedef struct {
    u8 pad[80];
    u8 *p;
    u8 pad2[1120 - 84];
} S_003E7430;
extern S_003E7430 D_001E2AC0[];
extern void func_003E7398(u8 *, f32);
void func_003E7430(s32 i, f32 a, f32 b) {
    u8 *p = (D_001E2AC0 + i)->p;
    if (*(s16 *)(p + 134) == 0) {
        *(f32 *)(*(u8 **)(p + 112) + 500) = a;
        func_003E7398(p, b);
    }
}
