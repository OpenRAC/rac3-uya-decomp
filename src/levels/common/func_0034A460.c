#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
} S_34A460b;

typedef struct {
    u8 pad0[0x68];
    S_34A460b *p68;
} S_34A460;

extern s32 func_0040C3D0(s32 *a0);
extern void func_00403C00(void (*a0)(void), S_34A460 *a1);
extern void func_0034A4C8(void);
extern void func_00436AE0(S_34A460 *a0);

void func_0034A460(S_34A460 *a0) {
    S_34A460b *t = a0->p68;
    if (func_0040C3D0(&t->w0) == 0) {
        func_0040C3D0(&t->w4);
        func_00403C00(func_0034A4C8, a0);
    } else {
        func_00436AE0(a0);
    }
}
