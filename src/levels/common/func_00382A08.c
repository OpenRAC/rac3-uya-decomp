#include "common.h"

/* localdecomp:start func_00382A08 */
typedef int Q_382A08 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_382A08;

typedef struct {
    V4_382A08 v;
    u8 pad10[0x30 - 0x10];
    s32 i30;
} S_382A08;

typedef struct {
    u8 pad0[16];
    V4_382A08 pos;
    u8 pad20[0x68 - 0x20];
    S_382A08 *s;
} O_382A08;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P_382A08;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 pad4[40];
    f32 f2C;
} R_382A08;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[238];
} T_382A08;

extern u8 D_00142647[];
extern T_382A08 D_002C5640[];
extern u8 D_001A4EC0[];
extern u8 D_001D66B0[8];
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
extern P_382A08 *func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern R_382A08 *func_00462190(void *, void *, s32, s32, f32, s32, s32, s32, s32, s32);

void func_00382A08(O_382A08 *self, V4_382A08 *from, V4_382A08 *to)
{
    V4_382A08 a;
    V4_382A08 b;
    V4_382A08 t;
    V4_382A08 c;
    V4_382A08 d;
    V4_382A08 v;
    S_382A08 *s;
    f32 len;
    f32 scale;
    f32 len2;
    s32 n;
    s32 k;
    s32 st;
    s32 size;
    s32 r;
    s32 kind;
    u32 col;
    u32 col2;
    P_382A08 *p;
    R_382A08 *q;

    a = *from;
    b = *to;
    s = self->s;
    scale = func_004408C0(0.75f, 1.0f) * 210000.0f;
    len = func_0040BF38(s);
    c = b;
    {
        Q_382A08 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(z));
    }
    n = len / 0.1f;
    func_0040C0F0(&d, &d, len / (f32)n);
    st = ((T_382A08 *)(D_00142647[0] * 0xF0 + (s32)D_002C5640))->unk1;
    if (st >= 2) {
        scale = func_004408C0(0.2f, 0.4f) * 210000.0f;
        n -= 5;
        if (n < 0) {
            n = 0;
        }
    }
    for (k = 0; k < n; k++) {
        size = func_00440918(1.0f, 3.0f);
        len2 = func_004408C0(0.1f, 0.2f) * 0.016666668f;
        func_0040BE90(&t, D_001A4EC0, -len2);
        r = func_00440878(12, 15);
        if (func_0013D3E0() & 2) {
            kind = 0x5F;
            col = 0x404040;
        } else {
            kind = 0x4F;
            col = 0x404050;
        }
        c.x += func_004408C0(0.35f, -0.35f);
        c.y += func_004408C0(0.35f, -0.35f);
        c.z += func_004408C0(0.35f, -0.35f);
        p = func_00466F98(&c, D_001D66B0, r, kind, col, size, scale, 10000.0f, 1.0f, 0.0f, 0.0f);
        {
            Q_382A08 x, y, z;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(c) : "j"(z));
        }
        if (p != 0) {
            if (st >= 2) {
                p->b2 = *D_00221118[91];
            } else {
                p->b2 = *D_00221118[23];
            }
            if (kind == 0x40) {
                p->b3 = 0x48;
            }
        }
    }
    if (s->i30 < 60 && func_00440848(2)) {
        func_0040BE90(&v, s, -0.033333335f);
        col2 = 0x7F80DFFF;
        func_00448CD0(&v, 0.10000001f);
        v.z += 0.050000004f;
        if (func_00440848(2)) {
            col2 = 0x7F407FFF;
        }
        q = func_00462190(&self->pos, &v, col2, 255, 94500.0f, func_00440878(10, 20), 0, -1, -1, 0);
        if (q != 0) {
            q->f2C = 0.0016666667f;
            q->b2 = *D_002211EC[0];
        }
    }
}
/* localdecomp:end func_00382A08 */
