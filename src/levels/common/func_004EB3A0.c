#include "common.h"

/* localdecomp:start func_004EB3A0 */
typedef struct {
    float x, y, z, w;
} V4_004EB3A0 __attribute__((aligned(16)));
typedef struct {
    u8 pad0[0x98];
    float f98;
    u8 pad1[0x1B4 - 0x9C];
    float f1B4;
    u8 pad2[0x344 - 0x1B8];
    float f344;
    u8 pad3[0x25F4 - 0x348];
    u8 flag;
} B_004EB3A0;
extern B_004EB3A0 D_001A4BE0;
extern V4_004EB3A0 D_001A4CD0;
extern float func_0040C3C8(float);
extern float func_0040C3E0(float);
extern void func_0040C2F8(V4_004EB3A0 *, V4_004EB3A0 *, void *);
extern void func_00440CF8(V4_004EB3A0 *, float, float, float);
void func_004EB3A0(float a) {
    V4_004EB3A0 v;
    V4_004EB3A0 t;
    float y;
    float s;
    float z;
    y = D_001A4BE0.f98;
    if (a <= 3.1415927f) {
        y = a;
    }
    s = D_001A4BE0.f1B4;
    if (D_001A4BE0.flag != 0) {
        z = 0.0f;
        t.x = func_0040C3C8(z) * s;
        t.y = func_0040C3E0(z) * s;
        t.z = z;
        func_0040C2F8(&t, &t, &D_001A4BE0);
        v = t;
    } else {
        func_00440CF8(&v, s, y, D_001A4BE0.f344);
    }
    D_001A4CD0 = v;
}
/* localdecomp:end func_004EB3A0 */
