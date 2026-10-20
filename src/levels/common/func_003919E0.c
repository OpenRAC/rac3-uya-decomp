#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef union {
    s128 q;
    f32 f[4];
} V_003919E0;

extern s32 func_00454168(s32, s32);
extern void func_00391638(void);
extern void func_00436220(u8 *);
extern s32 func_004562A0(V_003919E0 *, s32, f32);
extern void func_00391AC0(u8 *);
extern void func_00391D08(u8 *);
extern void func_00391938(u8 *);
extern void func_00391F48(u8 *);
extern void func_003923A0(u8 *);
extern void func_00392A48(u8 *);

void func_003919E0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    V_003919E0 t;
    if (a0 == 0) {
        return;
    }
    if (a0[32] == 254) {
        return;
    }
    if (a0[32] == 253) {
        return;
    }
    if (v == 0) {
        return;
    }
    if (func_00454168(*(s16 *)(a0 + 170), *(s32 *)(v + 40)) == 0) {
        func_00391638();
        func_00436220(a0);
        return;
    }
    t.q = *(s128 *)(a0 + 16);
    t.f[3] = 2.0f;
    if (func_004562A0(&t, 0, 100.0f) == -1) {
        return;
    }
    if (a0[32] != 6) {
        func_00391AC0(a0);
        func_00391D08(a0);
        func_00391938(a0);
    }
    func_00391F48(a0);
    func_003923A0(a0);
    func_00392A48(a0);
}
