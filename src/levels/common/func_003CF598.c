#include "common.h"

typedef int Q_003CF598 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CF598;

extern void func_003CF370(V4_003CF598 *a, V4_003CF598 *b);
extern void func_0041C768(V4_003CF598 *out, void *in, f32 f);
extern f32 D_001DEB70;
extern f32 D_001DEB74;

void func_003CF598(u8 *a0) {
    V4_003CF598 va;
    V4_003CF598 vb;
    V4_003CF598 vc;
    V4_003CF598 vt;
    u8 *s1;
    u8 *s2;

    s1 = *(u8 **)(a0 + 0x68);
    s2 = *(u8 **)(s1 + 0x94);
    if (*(s32 *)(s1 + 0x90) < 0) {
        va = *(V4_003CF598 *)(a0 + 0x10);
    } else {
        Q_003CF598 x0, y0, r0, t0, x1, y1, r1;
        func_0041C768(&va, a0 + 0xE0, D_001DEB70);
        func_0041C768(&vc, a0 + 0xD0, D_001DEB74);
        __asm__("lqc2 %0, %1" : "=j"(x0) : "m"(va));
        __asm__("lqc2 %0, %1" : "=j"(y0) : "m"(vc));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r0) : "j"(y0), "j"(x0));
        __asm__ __volatile__("lqc2 %0, %1" : "=j"(t0) : "m"(*(V4_003CF598 *)(a0 + 0x10)));
        __asm__("sqc2 %1, %0" : "=m"(vt) : "j"(t0));
        __asm__("sqc2 %1, %0" : "=m"(va) : "j"(r0));
        __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(va));
        __asm__("lqc2 %0, %1" : "=j"(y1) : "m"(vt));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(x1), "j"(y1));
        __asm__("sqc2 %1, %0" : "=m"(va) : "j"(r1));
    }
    if (*(s32 *)(s2 + 0x90) < 0) {
        vb = *(V4_003CF598 *)(*(u8 **)(s1 + 0x94) + 0x10);
    } else {
        Q_003CF598 x0, y0, r0, x1, y1, r1;
        func_0041C768(&vb, *(u8 **)(s1 + 0x94) + 0xE0, D_001DEB70);
        func_0041C768(&vc, *(u8 **)(s1 + 0x94) + 0xD0, -D_001DEB74);
        __asm__("lqc2 %0, %1" : "=j"(y0) : "m"(vb));
        __asm__("lqc2 %0, %1" : "=j"(x0) : "m"(vc));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r0) : "j"(x0), "j"(y0));
        __asm__("sqc2 %1, %0" : "=m"(vb) : "j"(r0));
        __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(vb));
        __asm__("lqc2 %0, %1" : "=j"(y1) : "m"(*(V4_003CF598 *)(*(u8 **)(s1 + 0x94) + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(x1), "j"(y1));
        __asm__("sqc2 %1, %0" : "=m"(vb) : "j"(r1));
    }
    func_003CF370(&va, &vb);
}
