#include "common.h"

extern void func_0040C5D0();

typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_0040C5D0();
extern void func_004C7FF0(O_A4DC8 *, f32, f32, s32, f32, f32 *);
void func_004C7F48(O_A4DC8 *o, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 m[16];
    if ((flag >> 24) != 0) {
        func_0040C5D0(m);
        m[0] = c * o->fC;
        m[10] = d * o->fC;
        func_004C7FF0(o, a, b, flag, e, m);
    }
}
