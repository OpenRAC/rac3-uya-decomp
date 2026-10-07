#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void func_003BD360(s32 p);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003BD8A0(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003BD8A0();
extern void func_003BB7B0(void);
extern void func_003BD868();
extern void func_003BD490();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B8F50 */
__asm__(".extern D_001D8D58_003B8F50, 4");
__asm__(".extern D_001D8D70_003B8F50, 4");
extern s32 D_001DA350_003B8F50;
extern u8 D_001DA354_003B8F50;
extern s32 D_001DA358_003B8F50;
extern s32 D_001DA35C_003B8F50;
extern s32 D_001D8D58_003B8F50;
extern s32 D_001D8D70_003B8F50;
extern u8 D_001D8D5C_003B8F50[8];
extern u8 D_001D8D74_003B8F50[8];
extern s32 D_002F8E44[];
extern void func_003B6528(s32, s32);
extern void func_003B6F28();
extern void func_003B87B8(s32, s32 *, s32);
extern s32 func_003B8840();
extern void func_003B8928();
extern void func_003B8E10();
extern void func_003B9030();
extern void func_003B9098();
s32 func_003B8F50(s32 a) {
    D_001DA350_003B8F50 = a;
    D_001DA354_003B8F50 = 0;
    D_001DA358_003B8F50 = 0;
    D_001DA35C_003B8F50 = 0;
    *(u8 *)0x1DA380 = 0;
    func_003B6528(0, 0);
    switch (D_001DA350_003B8F50) {
    case 0:
        func_003B6F28(4, &D_001D8D58_003B8F50);
        func_003B87B8(3, (s32 *)D_001D8D5C_003B8F50, D_001D8D58_003B8F50);
        break;
    case 1:
        func_003B6F28(4, &D_001D8D70_003B8F50);
        func_003B87B8(3, (s32 *)D_001D8D74_003B8F50, D_001D8D70_003B8F50);
        break;
    }
    func_003B8928(func_003B8840());
    func_003B8E10(func_003B9030);
    D_002F8E44[0] = (s32)func_003B9098;
    return 1;
}
/* localdecomp:end func_003B8F50 */

/* localdecomp:start func_003B9030 */
extern s32 func_003B9090();
extern void func_003B9880();
void func_003B9030(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x19E9:
        ok = 1;
        *(void **)(p + 0x64) = func_003B9090;
        break;
    case 0x1D98:
        ok = 1;
        *(void **)(p + 0x64) = func_003B9880;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003B9030 */

/* localdecomp:start func_003B9090 */
s32 func_003B9090(void) {
}
/* localdecomp:end func_003B9090 */

/* localdecomp:start func_003B9098 */
typedef int Q_3B9098 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9098;
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; } Sub_3B9098;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    u8 hA[2];
    f32 fC;
    V4_3B9098 v10;
    Sub_3B9098 s20;
} S_3B9098;
extern s32 func_003883C8(void *);
extern void func_003C7CE0(s32);
void func_003B9098(S_3B9098 *p) {
    Sub_3B9098 *s;
    V4_3B9098 v;
    Q_3B9098 a, b;
    if (func_003883C8(p->hA)) {
        func_003C7CE0((s32)p);
        return;
    }
    s = &p->s20;
    p->w4 = (p->w4 & 0xFFFFFF) | (((p->w4 >> 24) + s->b14) << 24);
    v.w = 0;
    v.x = s->f0;
    v.y = s->f4;
    v.z = s->f8;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(p->v10));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(a));
    s->f8 -= s->fC;
    p->b8 += s->b15;
    p->fC += s->f10;
}
/* localdecomp:end func_003B9098 */

/* localdecomp:start func_003B9160 */
typedef int u128_3B9160 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, fC, f10;
    u8 b14, b15;
    u8 pad16[6];
    void *f1C;
} Q_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_3B9160 v10;
    Q_3B9160 q;
} P_3B9160;
extern void *func_003C7B98(s32);
extern s32 func_0037E1D8(s32);
extern u8 *D_002F8FA0[];
extern void func_003B9098();
P_3B9160 *func_003B9160(u128_3B9160 *v, f32 *pos, s32 n, s32 a3, s32 t0, s32 t1, s32 t2,
                        f32 f0, f32 f1, f32 f2) {
    P_3B9160 *p = func_003C7B98(0x61);
    Q_3B9160 *q;
    if (p != 0) {
        p->v10 = *v;
        p->b1 = 0;
        p->fC = f0;
        p->x4 = (t1 << 24) | a3;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b8 = func_0037E1D8(0xFF);
        p->b2 = *D_002F8FA0[0];
        p->hA = n;
        q = &p->q;
        q->x = pos[0];
        q->y = pos[1];
        q->z = pos[2];
        q->f1C = func_003B9098;
        q->fC = f2;
        q->b15 = t0;
        q->f10 = (f1 - f0) / n;
        q->b14 = (t2 - t1) / n;
    }
    return p;
}
/* localdecomp:end func_003B9160 */

/* localdecomp:start func_003B92B8 */
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; u8 pad16[6]; void *f1C; } Sub_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3B9160 q10;
    Sub_3B9160 s20;
} S_3B9160;
typedef int Q_3B92B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B92B8;
extern void func_00388830(s32, s32, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388770(void *);
extern void func_00388700(void *, void *, f32);
extern f32 func_00388960(f32);
extern s32 func_0037E1D8();
extern f32 func_0037E250(f32, f32);
extern S_3B9160 *func_003B9160(Q_3B9160 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);
void func_003B92B8(u8 *obj, V4_3B92B8 *pos, V4_3B92B8 *tgt, f32 *ang) {
    V4_3B92B8 m0, m10, m20, m30, m40, m50, m60, m70;
    Q_3B92B8 x, y;
    f32 one, a, a1, a2, q;
    f32 l;
    one = 1.0f;
    m0 = *(V4_3B92B8 *)(obj + 0xC0);
    m10 = *(V4_3B92B8 *)(obj + 0xD0);
    func_00388830((s32)&m0, (s32)&m0, one);
    q = 0.1f;
    func_00388830((s32)&m10, (s32)&m10, one);
    func_00388758(&m20, &m0, &m10);
    m30 = m10;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*tgt));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(m50) : "j"(x));
    m40 = m50;
    l = func_00388770(&m40);
    func_00388700(&m50, &m30, l * q);
    a = *ang;
    a1 = a + 2.09439611f;
    a2 = a + 4.18878937f;
    if (3.14159274f < a1) a1 -= 6.28318548f;
    if (3.14159274f < a2) a2 -= 6.28318548f;

    func_00388830((s32)&m50, (s32)&m0, func_00388960(a) * 0.25f);
    func_00388830((s32)&m60, (s32)&m20, func_00388960(a) * 0.25f);
    {
        Q_3B92B8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m50));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
    }
    func_003B9160((Q_3B9160 *)&m70, (f32 *)&m30, 0x50, 0x808080, func_0037E1D8(0xC), 0x40, 0x20,
                  func_0037E250(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_0037E250(0.04f, q) * 0.0166666675f));

    func_00388830((s32)&m50, (s32)&m0, func_00388960(a1) * 0.25f);
    func_00388830((s32)&m60, (s32)&m20, func_00388960(a1) * 0.25f);
    {
        Q_3B92B8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m50));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(y));
    }
    func_003B9160((Q_3B9160 *)&m70, (f32 *)&m30, 0x50, 0x808080, func_0037E1D8(0xC), 0x40, 0x20,
                  func_0037E250(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_0037E250(0.04f, q) * 0.0166666675f));

    func_00388830((s32)&m50, (s32)&m0, func_00388960(a2) * 0.25f);
    func_00388830((s32)&m60, (s32)&m20, func_00388960(a2) * 0.25f);
    {
        Q_3B92B8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m50));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(y));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
    }
    func_003B9160((Q_3B9160 *)&m70, (f32 *)&m30, 0x50, 0x808080, func_0037E1D8(0xC), 0x40, 0x20,
                  func_0037E250(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_0037E250(0.04f, q) * 0.0166666675f));

    *ang -= func_0037E250(0.02f, 0.2f);
    if (*ang < -3.14159274f) *ang += 6.28318548f;
}
/* localdecomp:end func_003B92B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B9730);

/* localdecomp:start func_003B9880 */
extern void func_003B98B8();
extern void func_00385840();
extern void func_003B9730(void *);
void func_003B9880(void *p) {
    func_00385840(func_003B98B8, p);
    func_003B9730(p);
}
/* localdecomp:end func_003B9880 */

/* localdecomp:start func_003B98B8 */
typedef struct { u8 b[8]; } V8_3B98B8;
typedef struct { u128_t q[4]; } M4_3B98B8;
extern V8_3B98B8 D_001D8DB0[];
extern M4_3B98B8 D_001D8DC0[];
__asm__(".extern D_001D8E00, 1");
extern u8 D_001D8E00;
extern s32 D_001D9388;
extern void func_003BDAC8();
extern void func_003D3EE0();
extern void func_003CD830();
void func_003B98B8(void *p) {
    V8_3B98B8 v;
    u8 buf[0x80];
    M4_3B98B8 m;
    u8 out[0x90];
    s32 i;
    u8 *r;
    u8 *b = buf;
    v = D_001D8DB0[0];
    func_003BDAC8(p, 2, &v, b);
    r = b;
    m = D_001D8DC0[0];
    for (i = 1; i >= 0; i--) {
        func_003D3EE0(out, 0x16, 0x80808080, &D_001D8E00, &m, 1);
        func_003CD830(out, r, 0);
        r += 0x40;
    }
    D_001D9388 = D_001D9388 | 1;
}
/* localdecomp:end func_003B98B8 */

/* localdecomp:start func_003B99A0 */
extern u8 D_001DA354[];
extern u8 D_001DA380[];
extern s32 D_001D93A4[];
u8 func_003B8700(void);
s32 func_003B99A0(s32 a) {
    s32 r = 0;
    if ((D_001DA354[0] = func_003B8700()) != 0 && a) {
        r = D_001DA380[0] != 0;
    }
    D_001D93A4[0] = 1;
    return r;
}
/* localdecomp:end func_003B99A0 */

/* localdecomp:start func_003B9A08 */
__asm__(".extern D_001DA350, 4");
__asm__(".extern D_001D8D58, 4");
__asm__(".extern D_001D8D70, 4");
__asm__(".extern D_001DA380_003B9A08, 16");
__asm__(".extern D_001DA354_003B9A08, 16");
extern u8 D_001DA354_003B9A08;
extern volatile u8 D_001DA380_003B9A08;
extern s32 D_001DA350;
extern s32 D_001D8D58;
extern s32 D_001D8D70;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_00225780_003B9A08;
extern void func_003B7288();
extern s32 func_003B8A18();
extern s32 func_003B8A20();
extern void func_003B8C70();
extern void func_003B6488();
extern s32 func_003B8840();
extern void func_003B8968();
extern void func_003B8E10();
extern void func_003B8A48();
extern void func_00383848();
extern void func_003B9030();
extern void func_003B8A68();
void func_003B9A08(s32 a0) {
    s32 v;
    if (D_001DA354_003B9A08 != 0) {
        func_003B7288();
        if (func_003B8A18() == 1) {
            func_003B8C70();
        }
        if (func_003B8A18() > 0 && func_003B8A20() != 0) {
            func_003B6488();
        }
        if (D_001DA380_003B9A08 == 0) {
            v = 0;
            if (func_003B8A18() > 0 && a0 != 0) {
                switch (D_001DA350) {
                case 0:
                    v = D_001D8D58;
                    break;
                case 1:
                    v = D_001D8D70;
                    break;
                }
                D_001DA380_003B9A08 = 1;
            } else {
                v = func_003B8840();
            }
            func_003B8968(v);
            func_003B8E10(func_003B9030);
            func_003B8A48();
            func_00383848();
        }
    }
    {
        S_3B9A08 *g = &D_00225780_003B9A08;
        func_003B8A68(g->f34, g->h40, 0xF, 0xF);
    }
}
/* localdecomp:end func_003B9A08 */

/* localdecomp:start func_003B9B38 */
extern void func_003B8A48();
extern void func_003B7288();
 
void func_003B9B38(void) {
    func_003B8A48();
    func_003B7288();
}
/* localdecomp:end func_003B9B38 */

/* localdecomp:start func_003B9B60 */
extern u8 D_001DA390;
extern u8 D_001DA391;
extern s32 D_001D8E20;
extern s32 D_001D8E24;
extern void *D_002F8CC0;
extern void func_003B6528(s32, s32);
extern void func_003B6F28();
extern void func_003B87B8(s32, s32 *, s32);
extern s32 func_003B8840(void);
extern void func_003B8928(s32);
extern void func_003B9DA8(void);
extern void func_003B9BE8();
extern void func_003B8E10(void *);
extern void func_003B8D00(s32);
__asm__(".extern D_001DA390, 16");
__asm__(".extern D_001DA391, 16");
__asm__(".extern D_001D8E24, 16");
__asm__(".extern D_002F8CC0, 16");
s32 func_003B9B60(void) {
    register s32 first __asm__("$4") = 0;
    D_001DA390 = 0;
    D_001DA391 = 0;
    __asm__ volatile("" : : : "memory");
    {
        register s32 second __asm__("$5") = 0;
        func_003B6528(first, second);
    }
    func_003B6F28(4, &D_001D8E20);
    func_003B87B8(3, &D_001D8E24, D_001D8E20);
    func_003B8928(func_003B8840());
    {
        register u8 *callback __asm__("$2") = (u8 *)0x3C0000;
        register u8 *slot_base __asm__("$3") = (u8 *)0x300000;
        register u8 *handler __asm__("$4");
        __asm__ volatile("" : "+r"(callback), "+r"(slot_base));
        callback -= 0x6258;
        handler = (u8 *)0x3C0000;
        __asm__ volatile("" : "+r"(handler));
        *(void **)(slot_base - 0x7340) = callback;
        handler -= 0x6418;
        func_003B8E10(handler);
    }
    func_003B8D00(1);
    return 1;
}
/* localdecomp:end func_003B9B60 */

/* localdecomp:start func_003B9BE8 */
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x74]; s16 hAA; } S_3B9BE8;
extern s32 D_001D4B60[];
extern u8 func_0037DC58(void);
void func_003B9BE8(S_3B9BE8 *p) {
    if (p->hAA == 0x50A) {
        if (D_001D4B60[0] == 4 || ((s32 (*)(void))func_0037DC58)() > 0) {
            p->h34 |= 1;
        }
    }
    p->h34 |= 2;
}
/* localdecomp:end func_003B9BE8 */

/* localdecomp:start func_003B9C50 */
typedef int Q_3B9C50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9C50;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u8 padA[2];
    s32 wC;
    Q_3B9C50 q10;
    V4_3B9C50 v20;
    Q_3B9C50 q30;
} S_3B9C50;
typedef struct { u8 pad[4]; u8 b4; } T_3B9C50;
__asm__(".extern D_001D8E30, 4");
__asm__(".extern D_001D8E34, 4");
__asm__(".extern D_001D8E38, 4");
__asm__(".extern D_001D8E3C, 4");
__asm__(".extern D_001D8E40, 4");
__asm__(".extern D_001D8E44, 4");
__asm__(".extern D_001D8E48, 4");
__asm__(".extern D_001D8E4C, 4");
__asm__(".extern D_001D8E50, 4");
__asm__(".extern D_001D8E54, 1");
__asm__(".extern D_001D8E58, 1");
extern f32 D_001D8E30;
extern f32 D_001D8E34;
extern s32 D_001D8E38;
extern s32 D_001D8E3C;
extern s32 D_001D8E40;
extern s32 D_001D8E44;
extern s32 D_001D8E48;
extern s32 D_001D8E4C;
extern f32 D_001D8E50;
extern u8 D_001D8E54;
extern u8 D_001D8E58;
extern T_3B9C50 *D_002F9084[];
extern void *func_003C7B98(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_00388830(s32, s32, f32);
S_3B9C50 *func_003B9C50(V4_3B9C50 *a, V4_3B9C50 *b) {
    S_3B9C50 *p = func_003C7B98(0);
    V4_3B9C50 v, w, t;
    f32 f, k, z;
    s32 r1, r2;
    Q_3B9C50 x, y;
    if (p == 0) return 0;
    k = D_001D8E50;
    f = func_0037E250(D_001D8E30, D_001D8E34);
    r1 = func_0037E208(D_001D8E3C, D_001D8E40);
    r2 = func_0037E208(D_001D8E48, D_001D8E4C);
    *(Q_3B9C50 *)&v = *(Q_3B9C50 *)b;
    func_00388830((s32)&v, (s32)&v, f);
    p->w4 = D_001D8E38 | (r1 << 24);
    p->wC = D_001D8E44 | (r2 << 24);
    p->b9 = 0x64;
    p->b3 = D_001D8E58;
    p->b1 = D_001D8E54;
    p->b2 = D_002F9084[0]->b4;
    p->q10 = *(Q_3B9C50 *)a;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(x));
    w = t;
    p->v20 = w;
    *(f32 *)((u8 *)p + 0x1C) = k;
    p->v20.w = 1.0f;
    z = a->z + 5.0f;
    p->q30 = *(Q_3B9C50 *)b;
    *(f32 *)((u8 *)p + 0x3C) = z;
    return p;
}
/* localdecomp:end func_003B9C50 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B9DA8);

/* localdecomp:start func_003B9E98 */
typedef int Q_3B9E98 __attribute__((mode(TI)));
typedef struct { V4_3B9C50 a; V4_3B9C50 b; } E_3B9E98;
extern s32 func_003BD668_003B9E98(void *, s32);
extern S_3B9C50 *func_003B9C50(V4_3B9C50 *, V4_3B9C50 *);
extern void func_0037E2F0(V4_3B9C50 *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003886C0(void *, void *, void *, f32);
void func_003B9E98(void *a) {
    V4_3B9C50 v;
    V4_3B9C50 w;
    V4_3B9C50 t;
    Q_3B9E98 x, y;
    E_3B9E98 *e;
    s32 n;
    s32 i;
    e = (E_3B9E98 *)0x70000000;
    n = func_003BD668_003B9E98(a, 0);
    *(Q_3B9E98 *)&v = 0;
    v.z = 0.2f;
    *(f32 *)((u8 *)e + 0x1D4) += 1.32f;
    *(f32 *)((u8 *)e + 0x204) += -1.32f;
    func_003B9C50((V4_3B9C50 *)0x700001D0, &v);
    func_003B9C50((V4_3B9C50 *)0x70000200, &v);
    *(f32 *)((u8 *)e + 0x180) += -0.2f;
    *(f32 *)((u8 *)e + 0x188) += -0.15f;
    *(f32 *)((u8 *)e + 0x120) += -0.2f;
    *(f32 *)((u8 *)e + 0x128) += -0.15f;
    func_003B9C50((V4_3B9C50 *)0x70000180, &v);
    func_003B9C50((V4_3B9C50 *)0x70000120, &v);
    for (i = 0; i < n; i++, e++) {
        if (e->b.w == 0.0f) {
            *(Q_3B9E98 *)&w = *(Q_3B9E98 *)&e->a;
            w.w = 1.0f;
            func_0037E2F0(&t, 0.0f, e->a.w);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(w));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(w) : "j"(x));
        } else {
            func_003886C0(&w, &e->a, &e->b, func_0037E250(0.0f, 0.9f));
            w.x += func_0037E250(-e->a.w * 0.4f, e->a.w * 0.4f);
            w.y += func_0037E250(-e->a.w * 0.4f, e->a.w * 0.4f);
            w.w = 1.0f;
        }
        func_003B9C50(&w, &v);
    }
}
/* localdecomp:end func_003B9E98 */

/* localdecomp:start func_003BA0B8 */
extern s32 func_003B89F8(void);
extern void func_003B9E98(void *a);
void func_003BA0B8(void *a) {
    if (func_003B89F8() == 2) return;
    if (func_003B89F8() == 3) return;
    func_003B9E98(a);
}
/* localdecomp:end func_003BA0B8 */

/* localdecomp:start func_003BA108 */
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x15E]; s32 w1A0; } S_3BA108;
extern S_3BA108 D_00225780_003BA108[];
extern u32 D_001DA51C;
extern u32 D_001DA520;
extern u8 D_001DA390;
extern s32 D_001D8E20;
extern void func_003C2868();
extern void func_003B7288();
extern s32 func_003B8A18();
extern s32 func_003B8A20();
extern void func_003B6488();
extern void func_003B8C70();
extern s32 func_003B8840();
extern void func_003B8968();
extern void func_003B8E10();
extern void func_003B8A48();
extern void func_00383848();
extern void func_003B9BE8();
extern void func_003B8A68();
extern void func_003BA0B8();
__asm__(".extern D_001DA51C, 16");
__asm__(".extern D_001DA520, 16");
s32 func_003BA108(s32 a) {
    u32 p;
    s32 r;
    u8 t;
    S_3BA108 *g;
    r = 0;
    for (p = D_001DA51C; p < D_001DA520; p += 0x100) {
        func_003C2868(p);
    }
    D_001DA390 = func_003B8700();
    if (D_001DA390 != 0) {
        func_003B7288();
        if (func_003B8A18() == 1) {
            func_003B8C70();
        }
        if (func_003B8A18() > 0 && func_003B8A20() != 0) {
            func_003B6488();
        }
        t = *(u8 *)0x1DA391;
        if (a != 0) { if (t != 0) r = 1; }
        if (t == 0) {
            s32 v4;
            if (func_003B8A18() > 0 && a != 0) {
                v4 = D_001D8E20;
                *(u8 *)0x1DA391 = 1;
            } else {
                v4 = func_003B8840();
            }
            func_003B8968(v4);
            func_003B8E10(func_003B9BE8);
            func_003B8A48();
            func_00383848();
        }
    }
    g = D_00225780_003BA108;
    if (g->w1A0 != 0) func_003BA0B8(g->w1A0);
    func_003B8A68(g->w34, g->h40, 15, 15);
    return r;
}
/* localdecomp:end func_003BA108 */

/* localdecomp:start func_003BA280 */
extern void func_003B8A48();
extern void func_003B7288();
 
void func_003BA280(void) {
    func_003B8A48();
    func_003B7288();
}
/* localdecomp:end func_003BA280 */

/* localdecomp:start func_003BA2A8 */
extern f32 D_001DA3C0;
extern s32 D_001DA3B8;
extern u8 D_001DA3BC;
extern u8 D_001DA3C4[2];
extern s32 D_001D8E60;
extern u8 D_001D8E64[];
extern void *D_002F8E24[];
extern void func_003B6528(s32, s32);
extern void func_003B6F28();
extern s32 func_003B8840(void);
extern void func_003B8928(s32);
extern void func_003B8E10(void *);
extern void func_003BA3C8(void);
extern void func_003BA368();
extern void func_003BA748();
__asm__(".extern D_001D8E60, 4");
s32 func_003BA2A8(void) {
    D_001DA3C0 = 1.0f;
    D_001DA3B8 = 0;
    D_001DA3BC = 0;
    D_001DA3C4[0] = 0;
    D_001DA3C4[1] = 0;
    func_003B6528(0, 0);
    func_003B6F28(4, &D_001D8E60);
    func_003B87B8(3, (s32 *)D_001D8E64, D_001D8E60);
    func_003B8928(func_003B8840());
    func_003B8E10(func_003BA368);
    func_003BA3C8();
    D_002F8E24[0] = func_003BA748;
    return 1;
}
/* localdecomp:end func_003BA2A8 */

/* localdecomp:start func_003BA350 */
extern s32 D_0016C5E4[];
s32 func_003BA350(void) {
    return D_0016C5E4[0] == 1;
}
/* localdecomp:end func_003BA350 */

/* localdecomp:start func_003BA368 */
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_003BB210();
extern void func_003BA850(S_3BA368 *p);
void func_003BA368(S_3BA368 *p) {
    s32 r = 0;
    if (p->hAA == 0x1E01) {
        p->x64 = func_003BB210;
        func_003BA850(p);
        r = 1;
    }
    if (r) p->h34 &= ~2;
    else p->h34 |= 2;
}
/* localdecomp:end func_003BA368 */

/* localdecomp:start func_003BA3C8 */
extern void func_003A2DF8(void *);
extern u8 D_00319170[];
 
void func_003BA3C8(void) {
    func_003A2DF8(D_00319170);
}
/* localdecomp:end func_003BA3C8 */

/* localdecomp:start func_003BA3E8 */
extern u8 *D_001D6EEC[];
void func_003BA3E8(s32 a0, u8 *src) {
    u8 *p;
    s32 i;
    if (D_001D6EEC[0] == 0) return;
    p = D_001D6EEC[0];
    i = 0;
    do {
        i++;
        if (*(s32 *)(p + 0x48) == 0) {
            *(s32 *)(p + 0x38) = *(s32 *)(src + 0x38);
            *(s32 *)(p + 0x3C) = *(s32 *)(src + 0x3C);
            *(s32 *)(p + 0x30) = *(s32 *)(src + 0x30);
            *(s32 *)(p + 0x44) = *(s32 *)(src + 0x44);
            *(f32 *)(p + 0x24) = *(f32 *)(src + 0x24);
            *(f32 *)(p + 0x20) = *(f32 *)(src + 0x20);
            *(f32 *)(p + 0x28) = *(f32 *)(src + 0x28);
            *(s32 *)(p + 0x34) = *(s32 *)(src + 0x34);
            *(s32 *)(p + 0x2C) = *(s32 *)(src + 0x2C);
            *(s32 *)(p + 0x40) = *(s32 *)(src + 0x40);
            *(s32 *)(p + 0x4C) = *(s32 *)(src + 0x4C);
            *(u128_t *)(p + 0) = *(u128_t *)(src + 0);
            *(u128_t *)(p + 0x10) = *(u128_t *)(src + 0x10);
            *(s32 *)(p + 0x48) = a0;
            return;
        }
        p += 0x50;
    } while (i < 0x15E);
}
/* localdecomp:end func_003BA3E8 */

/* localdecomp:start func_003BA490 */
typedef int u128_3BA490 __attribute__((mode(TI)));
typedef struct {
    u128_3BA490 a;
    u128_3BA490 b;
    f32 f20, f24, f28;
    s32 x2C, x30, x34, x38, x3C, x40, x44, x48, x4C;
} P_3BA490;
extern void func_003A2EE0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E2A8(void);
extern s32 func_003894A0(s32, s32, f32);
void func_003BA490(s32 a0, u128_3BA490 *a, u128_3BA490 *b) {
    P_3BA490 s;
    func_003A2EE0(a0, 0x502020);
    s.x30 = s.x2C = func_003894A0(0x7F2F00, 0x800000, func_0037E250(0.0f, 1.0f));
    s.x38 = s.x34 = func_0037E208(0x1F, 0x3F);
    s.f28 = func_0037E250(0.1f, 0.8f);
    s.a = *a;
    s.b = *b;
    s.f24 = func_0037E2A8();
    s.f20 = func_0037E250(90.0f, 180.0f) * 0.017453292f * 0.016666668f;
    s.x40 = s.x44 = func_0037E208(0x96, 0xB4);
    s.x4C = 5;
    s.x3C = 1;
    func_003BA3E8(a0, (u8 *)&s);
}
/* localdecomp:end func_003BA490 */

/* localdecomp:start func_003BA5B8 */
typedef int Q_3BA5B8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; Q_3BA5B8 q10; u8 pad20[0x12]; s16 h32; } B_3BA5B8;
typedef struct {
    B_3BA5B8 *b;
    s32 w4;
    f32 f8;
    u8 bC, bD, bE, bF;
    union { Q_3BA5B8 q; f32 f[4]; } q10;
} Sub_3BA5B8;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3BA5B8 q10;
    Sub_3BA5B8 s20;
} S_3BA5B8;
extern void *func_003C7B98(s32);
extern s32 func_0037E1D8();
extern u8 *D_002F907C[];
extern void func_003888C8(void *, void *, void *);
S_3BA5B8 *func_003BA5B8(Q_3BA5B8 *pos, B_3BA5B8 *b, s32 a2, f32 f0, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f1, f32 f2, u8 a8, s32 a9) {
    S_3BA5B8 *p = func_003C7B98(0x59);
    Sub_3BA5B8 *s;
    Q_3BA5B8 t;
    s32 v;
    if (p) {
        p->w4 = a2;
        p->fC = f0;
        p->b1 = 0;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b8 = func_0037E1D8(0xFF);
        p->b2 = D_002F907C[0][a4];
        p->hA = a5;
        s = &p->s20;
        s->b = b;
        s->w4 = a3;
        s->f8 = f1;
        s->bC = a6;
        s->bD = a8;
        s->q10.q = *pos;
        s->q10.f[3] = f2;
        if (a4 == 0) s->bE = 1;
        s->bF = a9;
        if (b) {
            p->q10 = b->q10;
            func_003888C8(&t, &s->q10.q, (u8 *)b + 0xC0);
            __asm__ __volatile__(
                "lqc2 $vf1, %0\n"
                "lqc2 $vf2, %1\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, %0\n"
                : "+m"(p->q10) : "m"(t));
            if (a7 > 0) v = a7 >> 5;
            else v = b->h32 >> 5;
            p->b9 = v * 16 + 4;
        } else {
            p->q10 = *pos;
        }
    }
    return p;
}
/* localdecomp:end func_003BA5B8 */

/* localdecomp:start func_003BA748 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BA748;
typedef int Q_3BA748 __attribute__((mode(TI)));
typedef struct { s8 p0[0x20]; s8 b20; } O_3BA748;
typedef struct { O_3BA748 *obj; s32 f4; u8 p8[5]; u8 b0D; u8 pE[2]; V_3BA748 v10; } B_3BA748;
typedef struct { u8 p0[4]; s32 f4; u8 b8; u8 p9; s16 h0A; f32 fC; V_3BA748 v10; B_3BA748 b; } P_3BA748;
extern s32 func_003883C8();
extern void func_003C7CE0(s32);
extern void func_003BD9A0(u8 *, s32, u8 *);
extern void func_003888C8(void *, void *, void *);
void func_003BA748(P_3BA748 *p) {
    B_3BA748 *q;
    V_3BA748 m[4];
    Q_3BA748 x, y;
    O_3BA748 *o;
    q = &p->b;
    if (p->h0A >= 0) { if (func_003883C8(&p->h0A) != 0) { func_003C7CE0((s32)p); return; } }
    o = q->obj;
    if (o != 0) {
        if (o->b20 < 0) {
kill:
            func_003C7CE0((s32)p);
            return;
        }
        func_003BD9A0((u8 *)o, q->f4, (u8 *)m);
        func_003888C8(&p->v10, &q->v10, m);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v10));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m[3]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(x));
        p->v10.w = 0;
    } else {
        p->v10 = q->v10;
    }
    if (D_001DA3BC != 0) {
        p->f4 = (p->f4 & 0xFFFFFF) | ((s32)(*(f32 *)0x1DA3C0 * 128.0f) << 24);
    }
    p->fC = p->fC * q->v10.w;
    p->b8 = p->b8 + q->b0D;
}
/* localdecomp:end func_003BA748 */

/* localdecomp:start func_003BA850 */
__asm__(".extern D_001D8E94, 4");
__asm__(".extern D_001D8E98, 4");
__asm__(".extern D_001D8E9C, 4");
__asm__(".extern D_001D8EA0, 4");
extern u8 *D_001DA39C_003BA850[2];
extern u8 D_0037C0B0[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
extern u8 D_001DA398[8];
extern f32 D_001D8E94;
extern s32 D_001D8E98;
extern f32 D_001D8E9C;
extern f32 D_001D8EA0;
extern u8 *func_003BA5B8(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_003BA850(S_3BA368 *a) {
    s32 i;
    u8 **p = D_001DA39C_003BA850;
    u8 *e = D_0037C0B0;
    u8 *r;
    for (i = 5; i >= 0; i--) {
        if (*p == 0) {
            r = func_003BA5B8(e, (s32)a, D_001D8E98, 0, 0, -1, 0, -1, 0, 0, D_001D8E9C * 210000.0f, D_001D8EA0, 1.0f);
            *p = r;
            if (r != 0) r[3] = 0x44;
        }
        e += 0x10;
        p++;
    }
    { S_3BA850 *q = (S_3BA850 *)D_001DA398; q->f1C = D_001D8E94 * 0.016666668f; }
}
/* localdecomp:end func_003BA850 */

/* localdecomp:start func_003BA948 */
extern s32 D_001DA39C[];
extern void func_003C7CE0(s32);
void func_003BA948(void) {
    s32 *p = D_001DA39C;
    s32 i;
    for (i = 5; i >= 0; i--, p++) {
        if (*p) { func_003C7CE0(*p); *p = 0; }
    }
}
/* localdecomp:end func_003BA948 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA9A0);

/* localdecomp:start func_003BAE98 */
typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
__asm__(".extern D_001D8E90, 4");
__asm__(".extern D_001D8FF8, 4");
__asm__(".extern D_001D8FC4, 4");
__asm__(".extern D_001D8EB0, 4");
__asm__(".extern D_001D8FCC, 4");
__asm__(".extern D_001D8FC8, 4");
__asm__(".extern D_001D8FD0, 4");
__asm__(".extern D_001D8FD4, 4");
__asm__(".extern D_001D8FD8, 4");
__asm__(".extern D_001D8FDC, 4");
__asm__(".extern D_001D8FE8, 4");
__asm__(".extern D_001D8FEC, 4");
__asm__(".extern D_001D8FF0, 4");
__asm__(".extern D_001D8FF4, 4");
__asm__(".extern D_001D8FE0, 4");
__asm__(".extern D_001D8FE4, 4");
__asm__(".extern D_001D8FC0, 4");
extern f32 D_001D8E90;
extern f32 D_001D8FF8;
extern s32 D_001D8FC4;
extern s32 D_001D8EB0;
extern s32 D_001D8FCC;
extern s32 D_001D8FC8;
extern f32 D_001D8FD0;
extern f32 D_001D8FD4;
extern f32 D_001D8FD8;
extern f32 D_001D8FDC;
extern f32 D_001D8FE8;
extern f32 D_001D8FEC;
extern f32 D_001D8FF0;
extern f32 D_001D8FF4;
extern s32 D_001D8FE0;
extern s32 D_001D8FE4;
extern s32 D_001D8FC0;
extern f32 D_001DA3B4;
extern s32 D_001D9D80;
extern void func_003BD9A0();
extern void func_003A3EF0(s32, unsigned long);
extern void func_00388018(void);
extern void func_003888F0();
extern s32 func_003894A0(s32, s32, f32);
extern void func_003886E8(f32 *, void *, f32);
extern void func_003D41E0(void *, s32, s32, s32, s32, f32);
void func_003BAE98(void *p) {
    V4_3BAE98 m0[3];
    V4_3BAE98 m30;
    V4_3BAE98 m40[3];
    V4_3BAE98 m70;
    V4_3BAE98 m80[4];
    f32 k, ph, t, a, b, c, d, s, w;
    s32 i, j, odd, n, col, al, lo;
    Q_3BAE98 x, y;
    u8 ob;
    k = D_001DA3B4 / (D_001D8E90 * 0.0166666675f);
    if (D_001D8FF8 < k) {
        func_003BD9A0(p, 0, m80);
        k = 1.0f;
        ph = (f32)(D_001D9D80 % D_001D8FC4) / (f32)D_001D8FC4;
        func_003A3EF0(8, 0);
        func_003A3EF0(0x14, 0xFF9000000260UL);
        func_003A3EF0(0x47, 0x533F1);
        func_00388018();
        for (i = 0; i < 4; i++) {
            *(Q_3BAE98 *)&m0[0] = *(Q_3BAE98 *)&m80[1];
            *(Q_3BAE98 *)&m0[1] = *(Q_3BAE98 *)&m80[2];
            *(Q_3BAE98 *)&m0[2] = *(Q_3BAE98 *)&m80[0];
            func_003888F0(&m30, (V4_3BAE98 *)&D_001D8EB0 + i, m80);
            for (j = 0; j < D_001D8FCC; j++) {
                n = D_001D8FC8;
                t = (f32)((D_001DA3B8 + n / D_001D8FCC * j) % n) / (f32)n;
                ob = i & 1;
                if (ob) {
                    t += 0.5f;
                    if (1.0f < t) t -= 1.0f;
                }
                t = t * t;
                if (i < 2) {
                    w = (D_001D8FD4 - D_001D8FD0) * t * k + D_001D8FD0;
                    s = (D_001D8FDC - D_001D8FD8) * t + D_001D8FD8;
                } else {
                    w = (D_001D8FEC - D_001D8FE8) * t * k + D_001D8FE8;
                    s = (D_001D8FF4 - D_001D8FF0) * t + D_001D8FF0;
                }
                col = func_003894A0(D_001D8FE0, D_001D8FE4, t);
                lo = col & 0xFFFFFF;
                al = (s32)((f32)((u32)(col & 0xFF000000) >> 24) * k);
                col = lo | (al << 24);
                func_003886E8((f32 *)&m40[0], &m0[0], s);
                func_003886E8((f32 *)&m40[1], &m0[1], s);
                func_003886E8((f32 *)&m40[2], &m0[2], w);
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m30));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m40[2]));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
                func_003D41E0(m40, D_001D8FC0, col, 4, 1, ph + t + (f32)(i & 1) * 0.5f);
            }
        }
        func_003A3EF0(0x47, 0x5360B);
    }
}
/* localdecomp:end func_003BAE98 */

/* localdecomp:start func_003BB210 */
typedef int Q_3BB210 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BB210;
typedef struct { u8 pad[0x10]; V4_3BB210 v10; } S_3BB210;
__asm__(".extern D_001D8E70, 4");
extern s32 D_001D8E70;
extern V4_3BB210 D_00222480_003BB210[];
extern void func_00385688(void (*)(), s32);
extern void func_003BB4D8(void *);
extern void func_003BD9A0();
extern f32 func_00388770(void *);
extern void func_003888F0();
extern f32 func_0037E250(f32, f32);
extern void func_003BA490(s32, Q_3BB210 *, Q_3BB210 *);
void func_003BB210(S_3BB210 *p) {
    V4_3BB210 m0[4];
    V4_3BB210 m40;
    V4_3BB210 m50;
    V4_3BB210 m60;
    Q_3BB210 x, y;
    f32 one, l, r;
    V4_3BB210 *t, *q50, *q60;
    s32 i;
    func_00385688((void (*)())func_003BB4D8, (s32)p);
    one = 1.0f;
    func_003BD9A0(p, 0, m0);
    *(u8 *)0x1DA3BC = 0;
    *(f32 *)0x1DA3C0 = one;
    l = func_00388770(m0);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v10));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_00222480_003BB210[0]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(m40) : "j"(x));
    r = func_00388770(&m40) / l;
    if (20.0f < r) {
        *(u8 *)0x1DA3BC = 1;
        r = one - (r - 20.0f) / 40.0f;
        *(f32 *)0x1DA3C0 = r;
        if (r < 0.0f) *(f32 *)0x1DA3C0 = 0.0f;
    }
    q60 = &m60;
    q50 = &m50;
    t = (V4_3BB210 *)&D_001D8E70;
    for (i = 1; i >= 0; i--) {
        func_003888F0(q50, t++, m0);
        m60.x = 0.0f;
        m60.y = 0.0f;
        m60.z = func_0037E250(0.007f, 0.015f);
        func_003BA490((s32)p, (Q_3BB210 *)q50, (Q_3BB210 *)q60);
    }
}
/* localdecomp:end func_003BB210 */

/* localdecomp:start func_003BB398 */
__asm__(".extern D_001DA3B8_003BB398, 16");
extern s32 D_001DA3B8_003BB398;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 f40; } T_3BB398;
extern T_3BB398 D_00225780[];
extern void func_003B7288();
extern void func_003B8C70();
extern void func_003B6488();
extern void func_003B8968();
extern void func_003B8A48();
extern void func_003BA948();
extern s32 func_003B8A18();
extern s32 func_003B8A20();
u8 func_003B8700(void);
s32 func_003BB398(s32 a) {
    s32 r = 0;
    s32 arg;
    u8 t;
    s32 v;
    v = func_003B8700();
    *(u8 *)0x1DA3C4 = v;
    if ((v & 0xFF) != 0) {
        func_003B7288();
        if (func_003B8A18() == 1) func_003B8C70();
        if (func_003B8A18() > 0 && func_003B8A20() != 0) func_003B6488();
        t = *(u8 *)0x1DA3C5;
        if (a) { if (t != 0) r = 1; }
        if (t == 0) {
            if (func_003B8A18() > 0 && a) {
                arg = D_001D8E60;
                *(u8 *)0x1DA3C5 = 1;
            } else {
                arg = func_003B8840();
            }
            func_003B8968(arg);
            func_003B8A48();
            func_003BA3C8();
            func_003BA948();
            func_003B8E10(func_003BA368);
        }
    }
    func_003B8A68(D_00225780[0].f34, D_00225780[0].f40, 15, 15);
    D_001DA3B8_003BB398 = D_001DA3B8_003BB398 + 1;
    return r;
}
/* localdecomp:end func_003BB398 */

/* localdecomp:start func_003BB4D8 */
extern void func_003A3028();
extern s32 func_003BA350(void);
extern void func_003BA9A0(void *);
extern void func_003BAE98(void *);
void func_003BB4D8(void *p) {
    func_003A3028(p);
    if (func_003BA350()) func_003BA9A0(p);
    func_003BAE98(p);
}
/* localdecomp:end func_003BB4D8 */

/* localdecomp:start func_003BB520 */
extern void func_003B8A48();
extern void func_003B7288();
extern void func_003BA948();
 
void func_003BB520(void) {
    func_003B8A48();
    func_003B7288();
    func_003BA948();
    func_003BA3C8();
}
/* localdecomp:end func_003BB520 */

/* localdecomp:start func_003BB558 */
typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern S_3BB558 D_002CE040[];
extern void func_003B6528(s32, s32);
extern s32 func_0037DF98(s32); extern s32 func_11BB58(void *, s32, s32);
extern void func_003B8B10(f32);
s32 func_003BB558(void) {
    func_003B6528(0, 0);
    func_11BB58(D_002CE040, func_0037DF98(0x14D7), 0x40);
    D_002CE040[0].w40 = 0xB4;
    D_002CE040[0].w44 = 0;
    func_003B8B10(1.0f);
    return 1;
}
/* localdecomp:end func_003BB558 */

/* localdecomp:start func_003BB5C0 */
extern s32 func_00388398();
extern s32 func_003B8A20();
extern void func_003B6488();
s32 func_003BB5C0(s32 a) {
    S_3BB558 *g = D_002CE040;
    s32 r = 0;
    s32 k;
    switch (g->w44) {
    case 0:
        if (func_00388398(&g->w40) == 1) {
            g->w40 = 0xF;
            g->w44 = g->w44 + 1;
        }
        break;
    case 1:
        if (func_00388398(&g->w40) == 1) {
            g->w40 = 0x5A;
            g->w44 = g->w44 + 1;
        }
        func_003B8B10((f32)g->w40 / 15.0f);
        break;
    case 2:
        if (func_003B8A20()) func_003B6488();
        if (func_00388398(&g->w40) == 1 && a != 0) {
            g->w40 = 0xF;
            g->w44 = g->w44 + 1;
        }
        break;
    case 3:
        if (func_00388398(&g->w40) == 1) r = 1;
        func_003B8B10(1.0f - (f32)g->w40 / 15.0f);
        break;
    }
    return r;
}
/* localdecomp:end func_003BB5C0 */

/* localdecomp:start func_003BB730 */
extern s32 D_001D4BC0;
extern u8 D_002CE040_003BB730[];
extern void func_00384B68();
extern void func_0038C718(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00384C98();
void func_003BB730(void) {
    func_00384B68(1);
    func_0038C718(D_001D4BC0 >> 1, 0xA0, 0x80FFFFFF, D_002CE040_003BB730, -1, 1.2f);
    func_00384C98();
}
/* localdecomp:end func_003BB730 */

/* localdecomp:start func_003BB790 */
extern void func_003A2DF8(void *);
extern u8 D_00319170[];
 
void func_003BB790(void) {
    func_003A2DF8(D_00319170);
}
/* localdecomp:end func_003BB790 */

/* localdecomp:start func_003BB7B0 */
extern u8 D_001D8D50;
void func_003BB7B0(void) {
    D_001D8D50 = 0;
}
/* localdecomp:end func_003BB7B0 */

/* localdecomp:start func_003BB7B8 */
extern s32 D_002CE098[];
extern s32 func_11BB58(void *, s32, s32);
extern u8 D_001D8D50;
void func_003BB7B8(s32 a0) {
    D_001D8D50 = 1;
    func_11BB58(D_002CE098, a0, 0x40);
}
/* localdecomp:end func_003BB7B8 */

/* localdecomp:start func_003BB7E8 */
typedef struct { s32 f0; u8 p4[0x4C]; u8 f50; u8 f51; } S_BB7E8;
typedef struct { s32 a; s32 b; } P_BB7E8;
typedef struct { u8 p[0x68]; s32 f68; } T_BB7E8;
extern S_BB7E8 D_002CE088_003BB7E8[];
extern T_BB7E8 D_00227600[];
extern P_BB7E8 D_0037BAA8[];
extern s32 D_0037BAB0[];
extern s32 D_0037BAB4[];
extern s32 D_001D9060;
extern u8 D_001D9064[];
extern s32 D_00229930[];
extern s32 D_00225780_003BB7E8[];
extern s32 func_003B62D8();
extern void func_003B70A8();
extern void func_003A02D8();
extern void func_003BB9F0();
s32 func_003BB7E8(void) {
    s32 r, a, s, tmp;
    s32 *p;
    u8 *d;
    s32 t;
    S_BB7E8 *g;
    g = D_002CE088_003BB7E8;
    g->f50 = 0;
    g->f51 = 0;
    r = func_003B62D8();
    if (D_001D8D50) {
        D_001D8D50 = 0;
    } else {
        d = (u8 *)g + 0x10;
        if ((u32)(r - 1) < 2 || r == 4 || r == 8 || r == 0x1B || r == 0x1C || r == 9 || r == 0x1D
            || r == 5 || r == 0xD || r == 0x17 || r == 0xA || r == 0x12 || r == 0xE) {
            if (r > 0) a = D_0037BAA8[r % 60].b;
            else a = D_0037BAB4[0];
        } else {
            if (r > 0) a = D_0037BAA8[r % 60].a;
            else a = D_0037BAB0[0];
        }
        func_11BB58(d, func_0037DF98(a), 0x40);
    }
    func_003B6528(1, 0);
    func_003B6F28(5, &D_001D9060);
    func_003B87B8(4, (s32 *)D_001D9064, D_001D9060);
    s = D_00227600[0].f68;
    func_003B70A8(r, &tmp, s);
    D_002CE088_003BB7E8[0].f0 = s;
    s = s + tmp;
    D_00227600[0].f68 = s;
    func_003B8928(func_003B8840());
    func_003B8E10(func_003BB9F0);
    { s32 i = 0; while (D_00229930[i]) { D_00229930[i] = 0; i++; } }
    func_003A02D8(D_00225780_003BB7E8[0x15]);
    func_003BB790();
    return 1;
}
/* localdecomp:end func_003BB7E8 */

/* localdecomp:start func_003BB9F0 */
extern void func_003BBD70();
void func_003BB9F0(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x1E03:
        *(u16 *)(p + 0x34) |= 1;
        *(void **)(p + 0x64) = func_003BBD70;
        ok = 1;
        break;
    case 0xD54:
        *(void **)(p + 0x64) = 0;
        ok = 1;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003BB9F0 */

/* localdecomp:start func_003BBA50 */
typedef struct { u8 p0[0x24]; struct { u8 p[0x24]; f32 f24; } *w24; u8 p28[4]; f32 f2C; u8 p30[0x32]; u8 b62; u8 p63[0x32]; u8 b95; u8 p96[0x14]; s16 hAA; } Q_3BBA50;
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x12]; Q_3BBA50 *w54; } G_3BBA50;
extern G_3BBA50 D_00225780_003BBA50[];
extern u8 D_002CE088_003BBA50[];
extern u32 D_001DA51C;
extern u32 D_001DA520;
extern f32 D_001D6EF0;
extern Q_3BBA50 *D_001DA088;
extern Q_3BBA50 *D_00229930_003BBA50[];
extern void func_003C2868();
extern void func_003A04A0();
__asm__(".extern D_001DA51C, 16");
__asm__(".extern D_001DA520, 16");
__asm__(".extern D_001DA088, 16");
s32 func_003BBA50(s32 a) {
    u32 p;
    s32 r;
    f32 f;
    Q_3BBA50 **pp;
    Q_3BBA50 *q;
    s32 i;
    Q_3BBA50 *g;
    r = 0;
    for (p = D_001DA51C; p < D_001DA520; p += 0x100) {
        func_003C2868(p);
    }
    D_002CE088_003BBA50[0x50] = func_003B8700();
    D_00225780_003BBA50->w54->b95 = 0xE8;
    D_00225780_003BBA50->w54->b62 = 0xFF;
    if (D_002CE088_003BBA50[0x51] != 0) {
        if (D_00225780_003BBA50->h40 - 0x50 < D_00225780_003BBA50->w34) {
            f = (f32)(D_00225780_003BBA50->h40 - D_00225780_003BBA50->w34 - 4) * 0.013157895f;
            if (f < 0.0f) f = 0.0f;
            D_00225780_003BBA50->w54->f2C = D_00225780_003BBA50->w54->w24->f24 * f;
            D_001D6EF0 = f;
            g = *(Q_3BBA50 * volatile *)&D_001DA088;
            if (g != 0) {
                g->f2C = g->w24->f24 * f;
            }
            D_00225780_003BBA50->w54->b95 = (s32)(f * 232.0f);
            if (D_00225780_003BBA50->w54->hAA == 0xD54 && D_001DA088 == 0 && D_00229930_003BBA50[0] != 0) {
                i = 0;
                do {
                    D_00229930_003BBA50[i]->f2C = D_00229930_003BBA50[i]->w24->f24 * f;
                    i++;
                } while (D_00229930_003BBA50[i] != 0);
            }
        }
    }
    if (D_002CE088_003BBA50[0x50] != 0) {
        if (a != 0) r = D_002CE088_003BBA50[0x51] != 0;
    }
    func_003A04A0(D_00225780_003BBA50->w54, 1);
    return r;
}
/* localdecomp:end func_003BBA50 */

/* localdecomp:start func_003BBC48 */
extern s32 D_001D9060_003BBC48;
extern u8 D_002CE088_003BBC48[];
extern u8 D_00225780_003BBC48[];
extern void func_003B7288();
extern s32 func_003B8A18();
extern s32 func_003B8A20();
extern void func_003B6488();
extern void func_003B8C70();
extern s32 func_003B8840();
extern void func_003B8968();
extern void func_003B8E10();
extern void func_003B8A48();
extern void func_003BB790();
extern void func_003B8A68();
extern void func_003BB9F0();
__asm__(".extern D_001D9060_003BBC48, 4");
void func_003BBC48(s32 a0) {
    s32 v4;
    s32 v5;
    u8 *g;
    if (D_002CE088_003BBC48[0x50] != 0) {
        func_003B7288();
        if (func_003B8A18() == 1) {
            func_003B8C70();
        }
        if (func_003B8A18() > 0 && func_003B8A20() != 0) {
            func_003B6488();
        }
        if (D_002CE088_003BBC48[0x51] == 0) {
            if (func_003B8A18() > 0 && a0 != 0) {
                v4 = D_001D9060_003BBC48;
                D_002CE088_003BBC48[0x51] = 1;
            } else {
                v4 = func_003B8840();
            }
            func_003B8968(v4);
            func_003B8E10(func_003BB9F0);
            func_003B8A48();
            func_003BB790();
        }
    }
    g = D_00225780_003BBC48;
    v5 = *(s16 *)(g + 0x40);
    if (D_002CE088_003BBC48[0x51] != 0) {
        if (*(s32 *)(g + 0x34) >= 0x1F) v5 += 0x1E;
    }
    func_003B8A68(*(s32 *)(g + 0x34), v5, 7, 7);
}
/* localdecomp:end func_003BBC48 */

/* localdecomp:start func_003BBD70 */
extern void func_00385688(void (*)(), s32);
extern void func_003BBD98();
 
void func_003BBD70(s32 a0) {
    func_00385688(func_003BBD98, a0);
}
/* localdecomp:end func_003BBD70 */

/* localdecomp:start func_003BBD98 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BBD98;
typedef int Q_3BBD98 __attribute__((mode(TI)));
typedef struct {
    V_3BBD98 l0;
    V_3BBD98 v[4];
    u32 col[4];
    u8 pk[0x20];
    unsigned long g[4];
    V_3BBD98 a0, b0, c0, d0, e0, f0, o100, c110, v120, v130, v140;
} L_3BBD98;
extern u8 D_002CE088_003BBD98[];
extern u8 D_00225780_003BBD98[];
extern V_3BBD98 D_00222480_003BBD98;
__asm__(".extern D_1D9000_003BBD98, 4");
__asm__(".extern D_1D9040_003BBD98, 4");
extern u8 D_1D9000_003BBD98[8];
extern u8 D_1D9040_003BBD98[8];
extern void func_003B7190_003BBD98(s32, void *);
extern void func_003885F0_003BBD98(void *, void *, s32);
extern void func_003A3EF0_003BBD98(s32, unsigned long);
extern void func_00388830_003BBD98(void *, void *, f32);
extern void func_00388758_003BBD98(void *, void *, void *);
extern void func_003886E8_003BBD98(void *, void *, f32);
extern void func_003888F0_003BBD98(void *, void *, void *);
extern void func_003CD830_003BBD98();
extern void func_003BBF80_003BBD98(void *);
void func_003BBD98(u8 *arg) {
    L_3BBD98 l;
    Q_3BBD98 x, y;
    V_3BBD98 *p;
    V_3BBD98 *t;
    V_3BBD98 *w;
    V_3BBD98 *vb;
    u32 *c;
    s32 i;
    if (D_002CE088_003BBD98[0x51] != 0) {
        f32 m1 = -1.0f;
        u32 col = 0x80808080;
        func_003B7190_003BBD98(*(s32 *)D_002CE088_003BBD98, D_002CE088_003BBD98 + 8);
        l.l0 = *(V_3BBD98 *)(arg + 0x10);
        l.g[1] = *(unsigned long *)(D_002CE088_003BBD98 + 8);
        l.g[2] = 0xFF9000000260UL;
        l.g[3] = 0x8000000044UL;
        l.g[0] = 0;
        func_003885F0_003BBD98(l.pk, D_1D9040_003BBD98, 0x20);
        func_003A3EF0_003BBD98(0x47, 0x5360B);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_00222480_003BBD98));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(l.l0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(l.v120) : "j"(x));
        p = &l.v120;
        func_00388830_003BBD98(p, p, 1.0f);
        l.v130.x = 0;
        l.v130.y = 0;
        l.v130.z = m1;
        l.v130.w = 0;
        func_00388758_003BBD98(&l.v140, &l.v130, p);
        l.b0 = l.v120;
        l.c0 = l.v140;
        l.e0 = l.v140;
        l.f0 = l.v120;
        l.a0 = l.v130;
        func_003886E8_003BBD98(&l.o100, &l.a0, m1);
        l.c110 = l.l0;
        vb = l.v;
        p = vb;
        w = &l.e0;
        c = l.col;
        t = (V_3BBD98 *)D_1D9000_003BBD98;
        for (i = 3; i >= 0; i--) {
            *c = col;
            func_003886E8_003BBD98(p, t, 25.0f);
            t++;
            func_003888F0_003BBD98(p, p, w);
            p++;
            c++;
        }
        func_003CD830_003BBD98(vb, 0, 0);
        func_003A3EF0_003BBD98(0x47, 0x5360B);
    }
    {
        u8 *g = D_00225780_003BBD98;
        func_003BBF80_003BBD98(*(void **)(g + 0x54));
    }
}
/* localdecomp:end func_003BBD98 */

/* localdecomp:start func_003BBF80 */
extern void func_003A1340(void *);
extern void func_003A26D0(void *);
extern void func_003A3028();
void func_003BBF80(u8 *p) {
    if (p[0x95] < 11) return;
    func_003A1340(p);
    func_003A26D0(p);
    func_003A3028();
}
/* localdecomp:end func_003BBF80 */

/* localdecomp:start func_003BBFC8 */
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3BBFC8;
extern u8 D_002CE088[];
extern S_3BBFC8 D_00225780_003BBFC8;
extern void func_003B7618();
extern void func_00389920(s32);
extern void func_00384B68();
extern void func_00384C98();
extern void func_00389FB8_003BBFC8(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_003BBFC8(void) {
    s32 v;
    u8 *s;
    S_3BBFC8 *g;
    func_003B7618();
    s = D_002CE088;
    if (s[0x51] != 0) {
        func_00389920(1);
        func_00384B68(1);
        g = &D_00225780_003BBFC8;
        v = 0xE0 - (g->h40 - g->f34) * 3;
        if (v < 0) v = 0;
        if (v > 0xC0) v = 0xC0;
        if (v > 0) {
            func_00389FB8_003BBFC8(70.0f, (f32)(*(s32 *)0x1D4BC4 - 0x5A), (v << 24) | 0xC37A33, s + 0x10, -1, 1.5f, 1.5f, 0, 1, (unsigned long)(s32)0x80000000, 2.0f, 2.0f);
        }
        func_00384C98();
    }
}
/* localdecomp:end func_003BBFC8 */

/* localdecomp:start func_003BC0B8 */
extern s16 D_0016C5AC[];
 
void func_003BC0B8(void) {
    func_003B8A48();
    func_003B7288();
    func_003BB790();
    D_0016C5AC[0] = 1;
}
/* localdecomp:end func_003BC0B8 */

/* localdecomp:start func_003BC0F0 */
extern s32 func_0037DF98(s32);
extern void func_003B6528(s32, s32);
extern void func_003B6F28(s32, s32);
extern s32 func_0011B754(void *, s32);
__asm__(".extern D_001D90B8, 1");
extern u8 D_001D90B8;
extern volatile s32 D_001D4B4C;
typedef struct { u8 n0[0x10]; u8 n1[0x10]; u8 n2[0x10]; s32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50; u8 p54[0xC]; s8 f60; } S_BC0F0;
extern S_BC0F0 D_002CE0E0[];
typedef struct { u8 pad[0x1AF8]; s32 f1AF8; u8 p2[0x1B14-0x1AFC]; s32 f1B14, f1B18, f1B1C; } S_BC0F0b;
extern S_BC0F0b D_001A4BE0[];
s32 func_003BC0F0(s32 arg0, s32 arg1) {
    S_BC0F0 *p = D_002CE0E0;
    S_BC0F0b *q;
    func_0011B754(p->n0, func_0037DF98(0x1645));
    func_0011B754(p->n1, func_0037DF98(0x1646));
    func_0011B754(p->n2, func_0037DF98(0xF07));
    p->f30 = 0;
    q = D_001A4BE0;
    p->f34 = q->f1B14;
    p->f38 = q->f1B1C;
    p->f3C = q->f1B18;
    p->f40 = arg1;
    if (arg1 != 0 && q->f1AF8 != 0) {
        p->f40 = 0;
    }
    D_002CE0E0->f44 = arg0;
    D_002CE0E0->f60 = 0;
    func_003B6528(0, 0);
    if (D_002CE0E0->f40 == 0) {
        D_002CE0E0->f48 = 0;
        D_002CE0E0->f4C = 0x3C;
        D_002CE0E0->f50 = 0;
        D_001D4B4C = 0;
    } else {
        D_002CE0E0->f48 = 0;
        D_002CE0E0->f4C = 0x3C;
        func_003B6F28(3, (s32)&D_001D90B8);
    }
    return 1;
}
/* localdecomp:end func_003BC0F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BC218);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318A00);

/* localdecomp:start func_003BC568 */
typedef struct {
    char n0[0x10];
    char n1[0x10];
    char n2[0x10];
    f32 f30;
    s32 f34, f38, f3C, f40, f44, f48, f4C;
    f32 f50;
} S_3BC568;
extern S_3BC568 D_002CE0E0_003BC568;
__asm__(".extern D_001D9078, 4");
__asm__(".extern D_001D907C, 4");
__asm__(".extern D_001D9080, 4");
__asm__(".extern D_001D9084, 4");
__asm__(".extern D_001D9088, 4");
__asm__(".extern D_001D908C, 4");
__asm__(".extern D_001D9090, 4");
__asm__(".extern D_001D9094, 4");
__asm__(".extern D_001D9098, 4");
__asm__(".extern D_001D909C, 4");
__asm__(".extern D_001D90A0, 4");
__asm__(".extern D_001D90A4, 4");
__asm__(".extern D_001D90A8, 4");
__asm__(".extern D_001D90AC, 4");
__asm__(".extern D_001D90B0, 4");
extern f32 D_001D9078, D_001D907C, D_001D9080, D_001D9084, D_001D9088, D_001D908C;
extern f32 D_001D9090, D_001D9094, D_001D9098, D_001D909C, D_001D90A0, D_001D90A4;
extern s32 D_001D90A8;
extern f32 D_001D90AC, D_001D90B0;
extern s32 D_001D4BC4;
extern char D_001D90C8[], D_001D90D0[], D_001D90D8[];
extern long func_00384EC0(s32);
extern void func_00386D98(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_003869E8(s32, s32, s32, s32, s32, s32, s32, s32, f32, long, long);
extern void func_003867F8(s32, s32, s32, s32, long);
extern void func_11B2E8();
extern s32 func_11B868(char *);
extern s32 func_0038C510(char *, s32, f32);
extern f32 func_003BEB48(f32, f32, f32);

void func_003BC568(void) {
    if (D_002CE0E0_003BC568.f40 == 0) {
        s32 h = D_001D4BC4;
        s32 w = D_001D4BC0;
        s32 cx = w / 2;
        s32 cy = h / 2;
        s32 b = D_001D907C * (f32)h;
        s32 a = D_001D9078 * (f32)h;
        f32 t1, t2, x;
        func_00384B68(1);
        func_00386D98(0, 0, w, h, 0, 0, 0x100, 0x100, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0x808080, func_00384EC0(0x20));
        x = D_002CE0E0_003BC568.f30 + D_002CE0E0_003BC568.f30;
        if (1.0f < x) t1 = 1.0f; else t1 = x;
        x = (D_002CE0E0_003BC568.f30 - 0.5f) * 2.0f;
        if (x < 0.0f) t2 = 0.0f; else t2 = x;
        func_003869E8(cx - a / 2, cy - a / 2, a, a, 0, 0, 0x100, 0x100, D_002CE0E0_003BC568.f50, ((s32)(t2 * 128.0f) << 24) | 0x808080, func_00384EC0(0x22));
        func_003869E8(cx - b / 2, cy - b / 2, b, b, 0, 0, 0x100, 0x100, D_001D9080, ((s32)(t1 * 128.0f) << 24) | 0x808080, func_00384EC0(0x21));
        func_00384C98();
    } else {
        char s10[0x10];
        char s20[0x10];
        char s30[0x10];
        f32 sc11;
        f32 sc;
        s32 cy;
        s32 icon;
        f32 funit;
        s32 left;
        s32 right;
        f32 fw;
        f32 fbw;
        s32 lh;
        s32 cx;
        f32 sc14;
        f32 fh;
        s32 lh2;
        s32 unit;
        s32 lineh;
        s32 bw;
        f32 scale;
        s32 hh, hw;
        s32 h2, w2;
        fh = D_001D4BC4;
        unit = D_001D9090 * fh;
        funit = unit;
        fw = D_001D4BC0;
        cy = fh * 0.5f;
        bw = D_001D90A4 * funit;
        cx = fw * 0.5f;
        fbw = bw;
        icon = D_001D9094 * fbw;
        sc = D_001D90B0 * funit;
        lh = (f32)((s32)((0.5f - D_001D90A0) * funit) + 1) * 0.25f;
        left = cx - (s32)((0.5f - D_001D9098) * fbw);
        right = cx + (s32)((0.5f - D_001D909C) * fbw);
        sc14 = sc * 1.4f;
        sc11 = sc * 1.1f;
        lineh = D_001D90AC * funit;
        lh2 = lh >> 1;
        func_00384B68(1);
        hh = D_001D4BC4;
        hw = D_001D4BC0;
        h2 = hh >> 1;
        w2 = hw >> 1;
        func_003867F8(0, hh, 0, hw, (s32)0x80000000);
        func_003867F8(h2, h2 + (s32)((0.5f - D_001D9084) * funit), w2 - (s32)((0.5f - D_001D9088) * fbw), w2 + (s32)((0.5f - D_001D908C) * fbw), ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0x400000);
        func_00386D98(w2 - (bw >> 1), h2 - (unit >> 1), bw, unit >> 1, 0, 0, 0x100, 0x100, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0x808080, func_00384EC0(D_002CE0E0_003BC568.f44 - 7));
        func_00386D98(w2 - (bw >> 1), h2, bw, unit >> 1, 0, 0, 0x100, 0x100, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0x808080, func_00384EC0(0x16));
        func_11B2E8(s30, D_001D90C8, D_002CE0E0_003BC568.f3C / 3600, D_002CE0E0_003BC568.f3C / 60 % 60);
        if (D_002CE0E0_003BC568.f48 < 2) {
            func_11B2E8(s20, D_001D90D0);
            scale = sc11;
            func_11B2E8(s10, D_001D90D8, D_002CE0E0_003BC568.f34);
        } else if (D_002CE0E0_003BC568.f48 >= 3) {
            func_11B2E8(s20, D_001D90D8, D_002CE0E0_003BC568.f38);
            scale = sc11;
            func_11B2E8(s10, D_001D90D0);
        } else {
            s32 q = D_002CE0E0_003BC568.f4C / 4;
            s32 v = 0;
            if (D_002CE0E0_003BC568.f34 > 0) v = (f32)D_002CE0E0_003BC568.f38 * (f32)(D_002CE0E0_003BC568.f34 - q) / (f32)D_002CE0E0_003BC568.f34;
            func_11B2E8(s20, D_001D90D8, v);
            func_11B2E8(s10, D_001D90D8, q);
            scale = func_003BEB48(sc11, sc14, (f32)(D_002CE0E0_003BC568.f4C % 4) * 0.25f);
        }
        {
            s32 r2 = right - icon;
            func_0038C718(left + (func_0038C510(D_002CE0E0_003BC568.n2, func_11B868(D_002CE0E0_003BC568.n2), sc) >> 1), cy + lh2, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0xFFFFFF, D_002CE0E0_003BC568.n2, func_11B868(D_002CE0E0_003BC568.n2), sc);
            func_0038C718(r2 - (func_0038C510(s30, func_11B868(s30), sc) >> 1), cy + lh2, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0xFFFFFF, s30, func_11B868(s30), sc);
            func_0038C718(left + (func_0038C510(D_002CE0E0_003BC568.n0, func_11B868(D_002CE0E0_003BC568.n0), sc) >> 1), cy + lh + lh2, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0xFFFFFF, D_002CE0E0_003BC568.n0, func_11B868(D_002CE0E0_003BC568.n0), sc);
            func_00386D98(right - (icon >> 1), cy + lh + lh2, icon, icon, 0, 0, 0x40, 0x40, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0x808080, func_00384EC0(0x1D));
            func_0038C718(r2 - (func_0038C510(s10, func_11B868(s10), sc) >> 1), cy + lh + lh2, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0xFFFFFF, s10, func_11B868(s10), sc);
            func_00386D98(left, cy + lh * 2 + lh2, right - left, lineh, 0, 0, 1, 1, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0xFFFFFF, func_00384EC0(0x16));
            func_0038C718(left + (func_0038C510(D_002CE0E0_003BC568.n1, func_11B868(D_002CE0E0_003BC568.n1), sc) >> 1), cy + (lh * 2 + lh), ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0xFFFFFF, D_002CE0E0_003BC568.n1, func_11B868(D_002CE0E0_003BC568.n1), sc);
            func_00386D98(right - (icon >> 1), cy + (lh * 2 + lh), icon, icon, 0, 0, 0x20, 0x20, ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0x808080, func_00384EC0(0x1F));
            func_0038C718(right - D_001D90A8 - icon - (func_0038C510(s20, func_11B868(s20), scale) >> 1), cy + (lh * 2 + lh), ((s32)(D_002CE0E0_003BC568.f30 * 128.0f) << 24) | 0xFFFFFF, s20, func_11B868(s20), scale);
        }
        func_00384C98();
    }
}
/* localdecomp:end func_003BC568 */
TEXT_PADDING(2);

/* localdecomp:start func_003BCFB0 */
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[0x47]; s32 f68; u8 p6c[0x34]; u32 fA0; u8 pa4[0x5C]; } O_3BCFB0;
__asm__(".extern D_001DA520, 16");
__asm__(".extern D_001DA524, 16");
__asm__(".extern D_001D9D80, 16");
__asm__(".extern D_001DA440, 16");
extern u32 D_001DA520;
extern u32 D_001DA524;
extern s32 D_001D9D80;
extern s32 D_001DA440;
extern volatile u8 D_001D90F8;
extern s32 func_003C1DA0();
extern void func_003BD0D8();
extern void func_00388440();
extern int func_003BE3C0();
O_3BCFB0 *func_003BCFB0(s32 a, s32 b) {
    O_3BCFB0 *p;
    O_3BCFB0 *end;
    s32 r;
    end = (O_3BCFB0 *)D_001DA524;
    p = (O_3BCFB0 *)D_001DA520;
    if (p < (O_3BCFB0 *)D_001DA524) do {
        if (p->f20 < 0xFE) continue;
        if ((u32)D_001D9D80 < p->fA0) continue;
        r = 0;
        if (b) r = func_003C1DA0(b);
        if (r == 0 && b) break;
        if (p->f20 == 0xFF) *((u8 *)p + 0x120) = p->f20;
        func_003BD0D8(p, a);
        p->f68 = r;
        if (b) func_00388440(r, 0, b);
        if (D_001DA440) D_001DA440 = D_001DA440 - 1;
        return p;
    } while (++p < (O_3BCFB0 *)D_001DA524);
    if (D_001D90F8) func_003BE3C0();
    return 0;
}
/* localdecomp:end func_003BCFB0 */

/* localdecomp:start func_003BD0D8 */
typedef struct { u8 p0[0x6]; u8 b6; u8 p7[5]; u8 bC; u8 pD; u8 bE; u8 bF; s32 w10; u8 p14[0x10]; f32 f24; u8 p28[0x18]; s32 w40; u16 h44; u8 p46; u8 b47; struct { u8 p[0x10]; u8 b10; s8 b11; } *w48; } S_3BD0D8;
typedef struct {
    u8 p0[0x21]; u8 b21; u8 b22; u8 b23; S_3BD0D8 *w24; u8 p28[4]; f32 f2C; u8 p30[4]; u16 h34; s16 h36; u8 d38[8]; u8 p40[8]; s32 w48; f32 f4C; u8 p50[0x11]; u8 b61; u8 b62; u8 b63; s32 w64; u8 p68[4]; u8 b6C; u8 b6D; u8 b6E; u8 b6F; s32 w70; s32 w74; s32 w78; u8 p7C[2]; u8 b7E; u8 p7F[0x19]; s32 w98; u8 p9C[8]; u8 bA4; u8 bA5; u8 bA6; u8 bA7; u8 bA8; u8 pA9; s16 hAA; s32 wAC; u8 pB0[0xD]; u8 bBD;
} P_3BD0D8;
extern u8 D_002D7210[];
extern s16 D_002D7030[];
extern s32 D_002D9210[];
extern s32 D_002D6B80[];
extern S_3BD0D8 *D_002D67C0[];
extern u32 D_001DA51C;
__asm__(".extern D_001DA51C, 16");
void func_003BD0D8(P_3BD0D8 *p, s32 b) {
    u8 t;
    S_3BD0D8 *s;
    S_3BD0D8 *r;
    s32 v;
    func_00388440(p, 0, 0x100);
    t = D_002D7210[b];
    p->b23 = 0x80;
    p->b22 = t;
    p->bA8 = 0xFF;
    p->b21 = 0xFF;
    p->b61 = 0xFF;
    p->b62 = 0xFF;
    p->hAA = b;
    p->wAC = (((s32)p - (s32)D_001DA51C) >> 8) << 16;
    p->b6E = 0;
    p->b6C = 0xFF;
    p->bA4 = 0x7F;
    *(unsigned long *)p->d38 = 0x0040404000000000UL;
    p->bA6 = 0x80;
    p->h36 = 0x7F80;
    p->b6D = 0xFF;
    p->bA5 = 0x7F;
    p->bA7 = 0x80;
    if (D_002D7030[p->b22] != b) {
        p->h34 |= 5;
        p->w24 = 0;
        p->w98 = 0;
        p->w64 = D_002D9210[p->b22];
        if (p->w64 == 0) p->h34 |= 2;
    } else {
        v = D_002D6B80[p->b22];
        p->w64 = v;
        if (v == 0) p->h34 |= 2;
        s = D_002D67C0[p->b22];
        p->w24 = s;
        p->b62 = s->bE;
        p->h34 = p->h34 | s->h44;
        p->w98 = s->w10;
        p->f2C = s->f24;
        *(f32 *)&p->w48 = 1.0f;
        p->f4C = 1.0f;
        if (s->w40 != 0) {
            p->h34 |= 0x10;
            p->w78 = s->w40;
        }
        if (p->w24->bF != 0) {
            p->b6F = 0x18;
            p->h34 |= 0x400;
            p->w70 = 0;
            p->w74 = 0;
            p->bBD = 0;
        }
        if (p->w24->b6 != 0) p->b63 = 0x18;
        if (p->w24->w48 != 0) {
            func_003BD490(p);
            if (p->w24->w48->b10 >= 2) p->h34 &= 0xFFFD;
            r = p->w24;
            if (r->bC == 1) {
                if (r->w48->b10 < 2) {
                    p->w48 = 0;
                    if (r->w48->b11 < 0) p->h34 |= 0x40;
                }
            }
        }
        p->b7E |= p->w24->b47;
    }
}
/* localdecomp:end func_003BD0D8 */

/* localdecomp:start func_003BD360 */
__asm__(".extern D_001DA520, 16");
__asm__(".extern D_001DA530, 16");
__asm__(".extern D_001DA534, 16");
__asm__(".extern D_001D9D80, 16");
typedef struct { u8 pad[0x20]; u8 b20; u8 pad21[0x33]; s32 f54; u8 pad58[0x10]; s32 f68; u8 pad6C[0x34]; s32 fA0; } O_3BD360;
extern u32 D_001DA520; 
extern s32 D_001DA530; 
extern s32 D_001DA534; 
extern s32 D_001D9D80; 
extern void func_003C1F10();
extern void func_003BD778();
extern void func_003C23E8();
void func_003BD360(s32 arg) {
    O_3BD360 *o = (O_3BD360 *)arg;
    s32 p;
    if ((u32)o < D_001DA520) {
        o->b20 = 0xFD;
    } else {
        o->b20 = 0xFE;
        p = o->f68;
        if (p) {
            if (p >= D_001DA530 && p < D_001DA530 + D_001DA534 * 64) {
                func_003C1F10(p);
                o->f68 = 0;
            }
        }
        while (o->f54) {
            func_003BD778(o, o->f54);
        }
    }
    o->fA0 = D_001D9D80 + 2;
    func_003C23E8(o, 0x80807F7F);
}
/* localdecomp:end func_003BD360 */

/* localdecomp:start func_003BD428 */
extern int D_001DA54C;
extern int D_001DA53C;
extern int D_001DA548;
extern int D_001DA540;
extern int D_001DA544;
__asm__(".extern D_001DA544, 4");
extern void func_00388440(void *, int, int);

unsigned int func_003BD428(int count, int base) {
    int size;
    register int start __asm__("$3") = base;
    register int end __asm__("$2");
    size = count * 4;
    end = start + size;

    D_001DA54C = end;
    D_001DA53C = start;
    D_001DA548 = start;
    D_001DA540 = 0;
    D_001DA544 = 0;
    func_00388440((void *)start, 0, size);
    return (D_001DA54C + 0x3F) & 0xFFFFFFC0;
}
/* localdecomp:end func_003BD428 */

/* localdecomp:start func_003BD490 */
typedef struct { u8 p0[0x48]; u8 *tbl[1]; } C_3BD490;
typedef struct { u8 p0[0x24]; C_3BD490 *f24; u8 p28[0x18]; u8 b40; u8 b41; u8 b42; u8 b43; u8 p44[0x14]; s32 f58; s32 f5C; u8 p60[0xC]; u8 b6C; u8 p6D; u8 b6E; } S_3BD490;
extern u8 D_002CE180[];
void func_003BD490(S_3BD490 *s)
{
  u8 *new_var2;
  int new_var;
  if (s->b42 != 0xFF)
  {
    new_var2 = s->f24->tbl[s->b42] + (s->b40 * 4);
    s->f58 = *((s32 *) (new_var2 + 0x1C));
    s->b6E = s->f24->tbl[s->b42][0x12];
    s->b6C = s->f24->tbl[s->b42][0x11];
  }
  else
  {
    s->b6C = s->b42;
    s->b6E = 0;
    s->f58 = (s32) (D_002CE180 + (s->b40 << 11));
  }
  s->f5C = *((s32 *) ((s->f24->tbl[s->b43] + (new_var = s->b41 * 4)) + 0x1C));
}
/* localdecomp:end func_003BD490 */

/* localdecomp:start func_003BD550 */
typedef struct { u8 p0[0x24]; void *f24; u8 p28[0xC]; u16 h34; u8 p36[0x36]; u8 b6C; u8 b6D; u8 p6E[0xE]; u16 h7C; } S_3BD550;
extern u8 D_1A30B0[];
extern void func_0039FB08(u32);
extern s32 func_0039FE80();
void func_003BD550(S_3BD550 *p) {
    u8 *e;
    if (p->b6D != 0xFF) {
        e = D_1A30B0 + p->b6D * 128;
        if (*(S_3BD550 **)(e + 0xDC) != p) {
            p->b6D = 0xFF;
            return;
        }
        if (*(s16 *)(e + 0xCA) != p->b6C || (p->h34 & 0x40) || (p->h7C & 0x8000)) {
            func_0039FB08(p->b6D);
            p->b6D = 0xFF;
        }
    } else {
        if (p->b6C == 0xFF) return;
        if (p->h34 & 0x40) return;
        if (*(unsigned long *)((u8 *)p + 0x78) & 0x4800000000000UL) return;
        p->b6D = func_0039FE80(p->b6C, 4, p);
    }
}
/* localdecomp:end func_003BD550 */

LINKER_REMNANT("asm/remnants", func_003BD630);

/* localdecomp:start func_003BD668 */
/* MATCH */
extern s32 D_002F80A0[];
extern s32 D_001DA560;
__asm__(".extern D_001DA560, 16");
extern void func_003CC198();
s32 func_003BD668(u8 *obj, u8 *dst) {
    u8 *out = (u8 *)0x70000000;
    u8 *src;
    s32 i;
    s32 *cnt = (s32 *)0x70002000;
    if (dst != 0) out = dst;
    if (obj == 0) goto fail;
    if (*(u8 **)(obj + 0x24) == 0) return 0;
    if ((*(u8 **)(obj + 0x24))[0xF] == 0) goto fail;
    D_002F80A0[0] = (s32)obj;
    D_001DA560 = 1;
    D_002F80A0[1] = 0x1000;
    func_003CC198(cnt, 0x2000);
    if (*cnt == 0) {
fail:
        return 0;
    }
    src = (u8 *)0x70002030;
    i = 0;
    while (i < *cnt) {
        if (*(s16 *)src == 0) {
            u128_t v = *(u128_t *)(src + 0x10);
            __asm__("sq $0,%0" : "=m"(*(u128_t *)(out + 0x10)));
            src += 0x20;
            *(u128_t *)out = v;
            out += 0x20;
        } else if (*(s16 *)src == 1) {
            *(u128_t *)out = *(u128_t *)(src + 0x10);
            *(u128_t *)(out + 0x10) = *(u128_t *)(src + 0x20);
            src += 0x30;
            out += 0x20;
        }
        i++;
    }
    return *cnt;
}
/* localdecomp:end func_003BD668 */

LINKER_REMNANT("asm/remnants", func_003BD768);

/* localdecomp:start func_003BD778 */
typedef struct N_BD778 { u8 p0[8]; struct N_BD778 *next; } N_BD778;
typedef struct { u8 p0[0x54]; N_BD778 *head; } L_BD778;
extern void func_00388440(void *, s32, s32);
void func_003BD778(L_BD778 *l, N_BD778 *n) {
    N_BD778 *p;
    N_BD778 *h;
    if (n != 0) {
        h = l->head;
        if (h == n) {
            l->head = n->next;
        } else if (h != 0) {
            p = h;
            while (p->next != 0 && p->next != n) {
                p = p->next;
            }
            if (p->next == n) {
                p->next = n->next;
            }
        }
        func_00388440(n, 0, 0x40);
    }
}
/* localdecomp:end func_003BD778 */

/* localdecomp:start func_003BD810 */
extern s32 D_001DA480[];
extern s32 D_001DA4C0[];
s32 func_003BD810(s32 x) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_001DA480[i] == 0 || D_001DA480[i] == x) {
            D_001DA480[i] = x;
            D_001DA4C0[i] = 0;
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_003BD810 */

/* localdecomp:start func_003BD868 */
extern s32 D_001DA480[];
extern s32 D_001DA4C0[];
void func_003BD868(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        D_001DA480[i] = 0;
        D_001DA4C0[i] = 0;
    }
}
/* localdecomp:end func_003BD868 */

/* localdecomp:start func_003BD8A0 */
typedef struct { u8 p0[0x13]; u8 f13; } S_BDb;
typedef struct { u8 p0[0x48]; S_BDb *arr[1]; } S_BDt;
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[3]; S_BDt *f24; u8 p28[9]; u8 f31; u8 p32[0x10]; u8 f42; u8 f43; f32 f44; u8 p48[4]; f32 f4C; } S_BDa;
extern S_BDa *D_001DA480_003BD8A0[16];
extern s32 D_001DA4C0_003BD8A0[16];
extern void func_003C1A90();
void func_003BD8A0(void) {
    s32 i = 0;
    S_BDa *p;
    do {
        p = D_001DA480_003BD8A0[i];
        if (p != 0) {
            if (p->f20 & 0x80) { D_001DA480_003BD8A0[i] = 0; goto z; }
            if (p->f42 != 0xFF) { D_001DA480_003BD8A0[i] = 0; goto z; }
            if (p->f31 == 0 && D_001DA4C0_003BD8A0[i] >= 20) {
                if (p->f24->arr[p->f43]->f13 == p->f42) {
                    p->f44 = 1.0f - p->f4C;
                    func_003C1A90(D_001DA480_003BD8A0[i]);
                }
            } else {
                D_001DA4C0_003BD8A0[i]++;
            }
        } else {
z:
            D_001DA4C0_003BD8A0[i] = 0;
        }
        i++;
    } while (i < 16);
}
/* localdecomp:end func_003BD8A0 */

/* localdecomp:start func_003BD9A0 */
typedef struct { f32 x, y, z, w; } V4_3BD9A0;
typedef int Q_3BD9A0 __attribute__((mode(TI)));
extern void func_003C4F30();
extern void func_003886E8(f32 *, void *, f32);
extern void func_00388E38();
extern void func_00388F08();
void func_003BD9A0(u8 *a, s32 b, u8 *out) {
    s32 loc;
    f32 buf[16];
    f32 scale;
    Q_3BD9A0 x, y;
    loc = b;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_003C4F30(a, 1, &loc, out);
    func_003886E8((f32 *)(out + 0x30), out + 0x30, scale);
    func_00388E38(buf, a + 0xC0);
    func_00388F08(out, buf, out);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BD9A0 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BD9A0 *)(out + 0x30)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BD9A0 *)(out + 0x30)) : "j"(x));

}
/* localdecomp:end func_003BD9A0 */

/* localdecomp:start func_003BDA38 */
typedef struct { f32 x, y, z, w; } V4_3BDA38;
typedef int Q_3BDA38 __attribute__((mode(TI)));
extern void func_003C4F30();
extern void func_003886E8(f32 *, void *, f32);
extern void func_003888C8(void *, void *, void *);
void func_003BDA38(u8 *a, s32 b, f32 *out) {
    s32 loc;
    f32 buf[12];
    f32 v[4];
    f32 scale;
    Q_3BDA38 x, y;
    loc = b;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_003C4F30(a, 1, &loc, buf);
    func_003886E8(out, v, scale);
    func_003888C8(out, out, a + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDA38 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDA38 *)out));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDA38 *)out) : "j"(x));

}
/* localdecomp:end func_003BDA38 */
