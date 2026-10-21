#include "common.h"

/* localdecomp:start func_0037B2C8 */
typedef int Q_37B2C8 __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_37B2C8;

typedef struct {
    V4_37B2C8 v;
    s32 i10;
    s32 i14;
} S_37B2C8;

typedef struct {
    u8 pad0[16];
    V4_37B2C8 pos;
    u8 pad20[72];
    S_37B2C8 *s;
} O_37B2C8;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P_37B2C8;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 pad4[40];
    f32 f2C;
} R_37B2C8;

extern u8 D_001A4EC0[];
extern u8 *D_00221118[];
extern u8 *D_002211EC[];
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern s32 func_00440848(s32);
extern s32 func_0013D3E0(void);
extern void func_00448CD0(void *, f32);
extern P_37B2C8 *func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern R_37B2C8 *func_00462190(void *, void *, s32, s32, f32, s32, s32, s32, s32, s32);

void func_0037B2C8(O_37B2C8 *self, V4_37B2C8 *from, V4_37B2C8 *to) {
    V4_37B2C8 a;
    V4_37B2C8 b;
    V4_37B2C8 t;
    V4_37B2C8 c;
    V4_37B2C8 d;
    V4_37B2C8 v;
    S_37B2C8 *s;
    f32 len;
    f32 len2;
    s32 n;
    s32 k;
    s32 size;
    s32 r;
    s32 kind;
    u32 col;
    u32 col2;
    P_37B2C8 *p;
    R_37B2C8 *q;
    Q_37B2C8 x, y;

    s = self->s;
    a = *from;
    b = *to;
    len = func_0040BF38(s);
    c = b;
    __asm__(
        "lqc2 %0, %3\n"
        "lqc2 %1, %4\n"
        "vsub.xyz %0, %0, %1\n"
        "sqc2 %0, %2\n"
        : "=&j"(x), "=&j"(y), "=m"(d) : "m"(a), "m"(b));
    n = len / 0.1f;
    func_0040C0F0(&d, &d, len / (f32)n);
    for (k = 0; k < n; k++) {
        size = func_00440918(1.0f, 3.0f);
        len2 = func_004408C0(0.1f, 0.2f) * 0.016666668f;
        func_0040BE90(&t, D_001A4EC0, -len2);
        r = func_00440878(3, 6);
        if (func_0013D3E0() & 2) {
            kind = 64;
            col = 0xFF7F40;
        } else {
            kind = 96;
            col = 0xFF4040;
        }
        p = func_00466F98(&c, &t, r, kind, col, size, 63000.0039f, 10000.0f, 1.0f, 0.0f, 0.0f);
        __asm__(
            "lqc2 %0, %2\n"
            "lqc2 %1, %3\n"
            "vadd.xyz %0, %0, %1"
            : "=&j"(x), "=&j"(y) : "m"(c), "m"(d));
        __asm__("sqc2 %1, %0" : "=m"(c) : "j"(x));
        if (p != 0) {
            p->b2 = *D_00221118[23];
            p->b3 = (kind == 64) ? 72 : 68;
        }
    }
    if (s->i14 < 60 && func_00440848(2)) {
        func_0040BE90(&v, s, -0.0333333351f);
        col2 = 0x7F80DFFF;
        func_00448CD0(&v, 0.100000009f);
        v.z += 0.0500000045f;
        if (func_00440848(2)) {
            col2 = 0x7F407FFF;
        }
        q = func_00462190(&self->pos, &v, col2, 255, 94500.0f, func_00440878(10, 20), 0, -1, -1, 0);
        if (q != 0) {
            q->f2C = 0.00166666671f;
            q->b2 = *D_002211EC[0];
        }
    }
}
/* localdecomp:end func_0037B2C8 */
