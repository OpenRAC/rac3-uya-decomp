#include "common.h"

typedef int Q_36B888 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_36B888;
typedef struct {
    u8 pad0[0x46];
    u8 b46;
} R_36B888;
typedef struct {
    u8 pad0[0x24];
    R_36B888 *p24;
} P_36B888;
typedef struct {
    u8 pad0[0x18];
    P_36B888 *p18;
    u8 pad1C[0x20 - 0x1C];
    V_36B888 v20;
} G_36B888;
typedef struct {
    u8 pad0[0x27];
    u8 b27;
} H_36B888;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[0x6C - 2];
    f32 f6C;
    u8 pad70[240 - 0x70];
} E_36B888;
typedef struct {
    u8 pad0[0x54];
    s32 f54;
} S_36B888;
typedef struct {
    u8 pad0[0x68];
    S_36B888 *p68;
} O_36B888;
typedef struct {
    f32 x, y, z, w;
    u8 pad10[0x1C - 0x10];
    f32 f1C;
} __attribute__((aligned(16))) X_36B888;

extern s32 D_001A71A0[];
extern V_36B888 D_001EAAA0;
extern G_36B888 D_001EAA80;
extern H_36B888 D_001425C0;
extern E_36B888 D_002C5640[];
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, s32, s32);
extern void func_003887F8(void *, void *, void *, s32, f32);
extern void func_00369B98(void *, void *, void *, s32, f32);
extern f32 func_0040BFB0(void *, void *);
extern void func_00443840(void *, void *);
extern void func_0034BF98(void *, s32, void *);

/* localdecomp:start func_0036B888 */
P_36B888 *func_0036B888(O_36B888 *obj, V_36B888 *a, V_36B888 *b, X_36B888 *out, f32 f) {
    S_36B888 *s = obj->p68;
    V_36B888 tmp;
    Q_36B888 x, y;
    f32 d;
    P_36B888 *p;
    P_36B888 *ret;

    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    func_0040C0F0(out, out, 1.5f);
    out->w = 5627.9248f;
    if (func_003F8448(a, b, 16, D_001A71A0[0], 0) != 0) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(x));
        func_0040C0F0(&tmp, &tmp, 1.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001EAAA0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(x));
        if (s->f54) {
            func_003887F8(a, &tmp, &D_001EAAA0, 1, f);
        } else {
            func_00369B98(a, &tmp, &D_001EAAA0, 1, f);
        }
        if (D_001EAA80.p18 == 0) {
            goto zero;
        }
        {
            f = ((E_36B888 *)(D_001425C0.b27 * 240 + (u32)D_002C5640))->f6C;
            if (s->f54) {
                f *= 3.0f;
            }
            d = func_0040BFB0(&D_001EAA80.v20, a);
            if (d < 10.0f) {
                out->f1C = f;
            } else if (d < 14.0f) {
                out->f1C = f * 0.75f;
            } else if (d < 20.0f) {
                out->f1C = f * 0.5f;
            } else {
                out->f1C = f * 0.125f;
            }
            func_00443840(D_001EAA80.p18, out);
            if (((E_36B888 *)(D_001425C0.b27 * 240 + (u32)D_002C5640))->b1) {
                func_0034BF98(D_001EAA80.p18, 39, obj);
            }
            p = D_001EAA80.p18;
            if (p == 0 || p->p24 == 0) {
                goto zero;
            }
            ret = p;
            if (p->p24->b46 == 5) {
                goto end;
            }
            goto zero;
        }
    } else {
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(x));
        if (s->f54) {
            func_003887F8(a, &tmp, b, 0, f);
        } else {
            func_00369B98(a, &tmp, b, 0, f);
        }
    }
zero:
    ret = 0;
end:
    return ret;
}
/* localdecomp:end func_0036B888 */
