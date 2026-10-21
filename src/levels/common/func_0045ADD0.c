#include "common.h"
extern void func_0040C0F0(void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BF38(void *);
extern void func_0040CB80(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern void func_0040BCB8(void *, void *, int);

/* localdecomp:start func_0045ADD0 */
void func_0045ADD0(u8 *a, int unused, void *b) {
    f32 vc[12] __attribute__((aligned(16)));
    f32 vb[4] __attribute__((aligned(16)));
    f32 va[4] __attribute__((aligned(16)));
    f32 c;
    f32 s;
    f32 x;
    func_0040C0F0(va, 1.0f);
    func_0040BF20(vb, va, a + 0x20);
    func_0040BE90(vb, vb, 0.05f);
    c = func_0040BF38(vb);
    x = 1.0f - c * c;
    __asm__("sqrt.s %0, %1" : "=f"(s) : "f"(x));
    vb[3] = -s;
    func_0040CB80(vb, vc);
    func_0040C960(a, vc, a);
    if (b != 0) {
        func_0040BCB8(b, vc, 0x30);
    }
}
/* localdecomp:end func_0045ADD0 */
