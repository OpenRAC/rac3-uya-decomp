#include "common.h"

typedef struct { u8 p0[4]; f32 *f4; u8 p8[0x28]; u32 f30; u32 f34; } O_A6640;
void func_004C9880(O_A6640 *o, u32 n) {
    u32 a = o->f34; u32 m;
    if (a < n) m = a; else m = n;
    if ((f32)a == 0.0f) { *o->f4 = 0.0f; } else { *o->f4 = (f32)m / (f32)o->f34 * (f32)o->f30; }
}
