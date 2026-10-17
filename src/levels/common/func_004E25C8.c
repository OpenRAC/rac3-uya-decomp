#include "common.h"
typedef struct { u8 pad[164]; f32 a; f32 b; } S_004E25C8;
extern S_004E25C8 D_002F4580;
void func_004E25C8(f32 a, f32 b) {
    D_002F4580.a = a;
    D_002F4580.b = b;
}
