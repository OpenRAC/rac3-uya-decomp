#include "common.h"

typedef struct { s32 v[6]; } V24;
typedef struct { u8 pad[32]; f32 x, y, z; } S2E9D20;

extern V24 D_001D7BF8;
extern V24 D_001D7C10;
extern S2E9D20 D_002E9D20;
extern f32 func_004408C0(f32, f32);
extern s32 func_00440848(s32);
extern s32 func_00440878(s32, s32);
extern void func_00461128(f32, void *, void *, s32, s32, s32, s32, s32, s32, f32);
extern void func_002F95A0(f32, void *, void *, void *, s32, s32, s32, s32, s32);
extern void func_004A7200(s32, s32, void *);
extern void func_00300650(void *, void *, s32, s32);


/* localdecomp:start func_004488B8 */
void func_004488B8(u8 *p, void *q, s32 c, f32 a, f32 b) {
    f32 v[4] __attribute__((aligned(16)));
    V24 t1;
    V24 t2;
    s32 i;

    __asm__("sq $0,%0" : "=m"(v[0]));
    for (i = 0; i < 3; i++) {
        f32 r = func_004408C0(8.0f, 10.0f) * 0.016666668f;
        t1 = D_001D7BF8;
        t2 = D_001D7C10;
        func_00461128(a * 400000.0f, q, v,
                      t1.v[func_00440848(6)],
                      t2.v[func_00440848(6)],
                      func_00440878(15, 20), func_00440878(25, 30), 0, 0,
                      r * a);
    }
    if (p != 0) {
        func_002F95A0(a * 4.0f, p, q, v, 20, 127, 64, 0, 48);
        func_002F95A0(a * 3.0f, p, q, v, 29, 96, 32, 0, 32);
        if (p[32] != 254) {
            if (p[32] != 253) {
                if (c != -1) {
                    func_004A7200(c, 0, p);
                }
            }
        }
    }
    if (b != 0.0f) {
        if (0.0f < b) {
            D_002E9D20.y = b;
            D_002E9D20.z = b;
            D_002E9D20.x = b;
        } else {
            D_002E9D20.y = 13.0f;
            D_002E9D20.z = 13.0f;
            D_002E9D20.x = 13.0f;
        }
        func_00300650(&D_002E9D20, q, 0, 0);
    }
}
/* localdecomp:end func_004488B8 */
