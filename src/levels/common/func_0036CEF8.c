#include "common.h"

/* localdecomp:start func_0036CEF8 */
typedef int Q_36CEF8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_36CEF8;

typedef struct {
    u8 pad0[16];
    V4_36CEF8 pos;
    u8 pad20[50 - 32];
    u16 unk32;
    u8 pad34[188 - 52];
    u8 unkBC;
    u8 padBD[192 - 189];
    V4_36CEF8 unkC0;
    V4_36CEF8 unkD0;
} S_36CEF8;

extern void func_0040BAF0(u8 *);
extern void func_0040BE90(V4_36CEF8 *, V4_36CEF8 *, f32);
extern s32 func_00440848(s32);
extern u8 *func_004633E8(f32, V4_36CEF8 *, f32, f32, s32, V4_36CEF8 *, f32, u32, s32);

void func_0036CEF8(S_36CEF8 *obj) {
    V4_36CEF8 a;
    V4_36CEF8 b;
    V4_36CEF8 c;
    Q_36CEF8 x;
    Q_36CEF8 y;
    s32 i;
    s32 n;
    s32 f;
    f32 z;
    u8 *r;
    u8 *q;
    u8 *r2;
    u8 *q2;
    s32 j;

    if (obj->unkBC == 0) {
        return;
    }
    func_0040BAF0(&obj->unkBC);
    func_0040BE90(&a, &obj->unkD0, 0.1f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->pos));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    func_0040BE90(&b, &obj->unkC0, 0.275f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(y));
    func_0040BE90(&c, &obj->unkD0, 0.10000001f);
    for (i = 0; i < 4; i++) {
        n = func_00440848(16);
        if (func_00440848(2) != 0) {
            n = -n;
        }
        r = func_004633E8(0.04f, &a, 1.0f, 0.9f, n, &c, 84000.0f, 0x7F204080, 0);
        if (r != 0) {
            *(s16 *)(r + 10) = 8;
            r[9] = (((s32)(obj->unk32 << 16) >> 21) << 4) + 4;
            q = r + 32;
            *(s32 *)(q + 4) = 2;
            q[10] = 127;
            q[11] = r[10];
        }
    }
    n = 16;
    f = 2;
    z = 15750.001f;
    for (j = 0; j < 3; j++) {
        r2 = func_004633E8(0.02f, &a, 1.0f, 1.0f, n, &c, z, 0x7FFFFFFF, 0);
        if (r2 != 0) {
            r2[9] = (((s32)(obj->unk32 << 16) >> 21) << 4) + 4;
            *(s16 *)(r2 + 10) = f;
            q2 = r2 + 32;
            r2[8] = func_00440848(255);
            *(s32 *)(q2 + 4) = 2;
            q2[10] = 127;
            q2[11] = r2[10];
        }
        n = -n;
        f <<= 1;
        z -= 3150.0f;
    }
}
/* localdecomp:end func_0036CEF8 */
