#include "common.h"

typedef int Q38E930 __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V38E930;

typedef struct {
    u8 pad0[16];
    V38E930 pos;
} O38E930;

typedef struct {
    u8 pad0[92];
    u8 *unk5C;
    u8 pad60[40];
    u8 *unk88;
    u8 pad8C[280];
    u8 *unk1A4;
} S38E930;

extern S38E930 D_00221118;
extern void func_00440B30(V38E930 *, f32, f32);
extern void func_0040BE90(V38E930 *, V38E930 *, f32);
extern s32 func_00440878(s32, s32);
extern u8 *func_0046DCB8(V38E930 *, V38E930 *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_00440848(s32);
extern void func_004C41E8(V38E930 *, V38E930 *);
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(V38E930 *, V38E930 *, f32);
extern void func_00463938(V38E930 *, V38E930 *, s32, f32, f32);

/* localdecomp:start func_0038E930 */
void func_0038E930(O38E930 *o) {
    V38E930 pos;
    V38E930 dir;
    V38E930 tmp;
    V38E930 v48;
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    s32 b;
    u8 *e;
    f32 f;
    Q38E930 x, y, r;

    for (i = 0; i < 1; i++) {
        func_00440B30(&dir, 0.035f, 0.05f);
        func_0040BE90(&tmp, &dir, 10.0f);
        {
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(tmp));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
        }
        a = func_00440878(10, 30);
        b = func_00440878(-1, -3);
        e = func_0046DCB8(&pos, &dir, a, 0x5A182, b, 32, 0, 0, 94500.0f, 199500.0f, 0.006666667f);
        if (e != 0) {
            e[3] = func_00440848(2) ? 72 : 68;
            e[2] = D_00221118.unk5C[0];
        }
    }
    for (j = 0; j < 1; j++) {
        func_00440B30(&dir, 0.01f, 0.04f);
        func_0040BE90(&tmp, &dir, 10.0f);
        {
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(tmp));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
        }
        a = func_00440878(10, 30);
        b = func_00440878(-1, -3);
        e = func_0046DCB8(&pos, &dir, a, 0x5A182, b, 32, 0, 0, 73500.0f, 52500.0f, 0.006666667f);
        if (e != 0) {
            e[3] = func_00440848(2) ? 72 : 68;
            e[2] = D_00221118.unk1A4[0];
        }
    }
    for (k = 0; k < 1; k++) {
        func_00440B30(&dir, 0.01f, 0.03f);
        func_0040BE90(&tmp, &dir, 10.0f);
        {
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(tmp));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
        }
        a = func_00440878(10, 30);
        b = func_00440878(-1, -3);
        e = func_0046DCB8(&pos, &dir, a, 0x5A182, b, 32, 0, 0, 73500.0f, 31500.002f, 0.006666667f);
        if (e != 0) {
            e[3] = func_00440848(2) ? 72 : 68;
            e[2] = D_00221118.unk88[0];
        }
    }
    if (!func_00440848(3)) {
        func_00440B30(&dir, 0.01f, 0.03f);
        func_0040BE90(&tmp, &dir, 20.0f);
        {
            Q38E930 x, y;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(tmp));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
        }
        func_004C41E8(&o->pos, &v48);
        f = func_004408C0(0.01f, 0.05f);
        func_0040C0F0(&v48, &v48, -f);
        func_00463938(&pos, &v48, 0x4005A182, -1.0f, -0.0027777778f);
    }
}
/* localdecomp:end func_0038E930 */
