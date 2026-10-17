#include "common.h"
typedef struct { u8 pad[340]; f32 a; f32 b; } S_004E25E0;
extern S_004E25E0 D_002F4580;
void func_004E25E0(f32 a, f32 b) {
    D_002F4580.a = a;
    D_002F4580.b = b;
}
