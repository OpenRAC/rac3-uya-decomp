#include "common.h"

/* localdecomp:start func_0040A478 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s32 n;
    f32 f4;
    u8 pad8[16];
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 data[1];
} P_0040A478;

extern void func_0040A590(void *, s32, void *, f32);
extern f32 func_004408C0(f32, f32);
extern s32 func_0040D020(s32, s32, f32);
extern void func_0040A760(void *, s32, s32 *, s32 *, void *, f32, f32, f32);

void func_0040A478(s32 *a0, P_0040A478 *a1)
{
    s128 buf[a1->n];
    s32 a[4];
    s32 b[4];
    f32 f20;
    f32 f22;
    f32 f21;

    func_0040A590(buf, a1->n, a0, a1->f18);
    f20 = func_004408C0(a1->f2C, a1->f30);
    f22 = func_004408C0(a1->f1C, a1->f20);
    f21 = func_004408C0(a1->f24, a1->f28);
    a[0] = func_0040D020(0, a0[8], f20);
    a[1] = func_0040D020(0, a0[9], f20);
    b[0] = func_0040D020(0, a0[10], f20);
    b[1] = func_0040D020(0, a0[11], f20);
    func_0040A760(buf, a1->n, a, b, a1->data, f22, f21, a1->f4);
}
/* localdecomp:end func_0040A478 */
