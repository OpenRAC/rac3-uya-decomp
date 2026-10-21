#include "common.h"

/* localdecomp:start func_0039A1D8 */
typedef int Q_39A1D8 __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_39A1D8;

typedef struct {
    u8 pad0[0x46];
    u8 b70;
} X_39A1D8;

typedef struct {
    u8 pad0[0x10];
    V4_39A1D8 pos;
    u8 pad20[4];
    X_39A1D8 *p24;
    u8 pad28[0x34 - 0x28];
    u16 h52;
    u8 pad36[0xAA - 0x36];
    u16 h170;
} E_39A1D8;

typedef struct {
    u8 pad0[0x10];
    V4_39A1D8 pos;
    u8 pad20[0x48];
    void *p68;
} O_39A1D8;

typedef struct {
    u8 pad0[0x10];
    f32 f16;
} R_39A1D8;

typedef struct {
    V4_39A1D8 pos;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[4];
    s32 w20;
} __attribute__((aligned(16))) D_39A1D8;

typedef struct {
    u8 pad0[0x77];
    u8 b119;
} S_1425C0;

typedef struct {
    u8 pad0;
    u8 b1;
    u8 pad2[0x6A];
    f32 f108;
    u8 pad70[0xF0 - 0x70];
} S_2C5640;

typedef struct {
    u8 pad0[0x25C0];
    E_39A1D8 *p25C0;
} S_1A4BE0;

typedef struct {
    u8 pad0[0x9C];
    s32 f9C;
    u8 padA0[0xB0 - 0xA0];
} S_2A1EF0;

extern S_1425C0 D_001425C0;
extern S_2C5640 D_002C5640[];
extern S_1A4BE0 D_001A4BE0;
extern E_39A1D8 *D_001EEB00[];
extern V4_39A1D8 D_001EAAA0;
extern S_2A1EF0 D_002A1EF0[];
extern s32 D_001DE130;
extern f32 D_001E20E4;

static __inline__ S_2C5640 *cur_39A1D8(void) {
    return &D_002C5640[D_001425C0.b119];
}

extern s32 func_004C7670(void);
extern void func_004C6EC8(V4_39A1D8 *, V4_39A1D8 *);
extern s32 func_0040BA90(void *);
extern s32 func_003FB1D0(V4_39A1D8 *, s32, O_39A1D8 *, s32, f32);
extern R_39A1D8 *func_00440728(E_39A1D8 *);
extern void func_004C41E8(V4_39A1D8 *, V4_39A1D8 *);
extern void func_0040C0F0(V4_39A1D8 *, V4_39A1D8 *, f32);
extern void func_0039AA18(O_39A1D8 *, V4_39A1D8 *, s32);
extern void func_00443628(V4_39A1D8 *, O_39A1D8 *, s32, V4_39A1D8 *, f32);
extern void func_00443840(E_39A1D8 *, D_39A1D8 *);
extern f32 func_00440978(void);
extern void func_00440CF8(V4_39A1D8 *, f32, f32, f32);
extern s32 func_003F8448(V4_39A1D8 *, V4_39A1D8 *, s32, O_39A1D8 *, s32);
extern void func_0039ACB0(O_39A1D8 *);
extern void func_004026A0(void *, O_39A1D8 *);
extern void func_0039A510();
extern void func_00436220(O_39A1D8 *);

void func_0039A1D8(O_39A1D8 *obj) {
    V4_39A1D8 b;
    V4_39A1D8 a;
    V4_39A1D8 c;
    D_39A1D8 d;
    void *p = obj->p68;
    s32 n;
    s32 i;
    R_39A1D8 *r;
    X_39A1D8 *x;
    u8 t;
    f32 f;

    if (func_004C7670()) {
        func_004C6EC8(&obj->pos, &obj->pos);
    }
    if (!func_0040BA90(p)) {
    n = func_003FB1D0(&obj->pos, 1, obj, 0, D_001E20E4);
    if (n != 0 && cur_39A1D8()->b1 >= 2) {
        for (i = 0; i < n; i++) {
            Q_39A1D8 q0, q1, q2;
            r = func_00440728(D_001EEB00[i]);
            if (r == 0) continue;
            if (!(D_001EEB00[i]->h52 & 0x4000)) continue;
            if (D_001EEB00[i] == D_001A4BE0.p25C0) continue;
            if (D_001EEB00[i] == 0) continue;
            x = D_001EEB00[i]->p24;
            if (x == 0) continue;
            t = x->b70;
            if (t != 5) continue;
            func_004C41E8(&obj->pos, &a);
            func_0040C0F0(&a, &a, r->f16);
            __asm__("lqc2 %0, %1" : "=j"(q0) : "m"(a));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(D_001EEB00[i]->pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(q2) : "j"(q1), "j"(q0));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(q2));
            func_0039AA18(obj, &b, 5);
            __asm__("lqc2 %0, %1" : "=j"(q0) : "m"(obj->pos));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(D_001EEB00[i]->pos));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(q2) : "j"(q1), "j"(q0));
            __asm__("sqc2 %1, %0" : "=m"(c) : "j"(q2));
            func_0040C0F0(&c, &c, 1.5f);
            func_0040C0F0(&d.pos, &d.pos, 2.0f);
            func_00443628(&d.pos, obj, 0x110000, &c, cur_39A1D8()->f108 * 0.001f);
            d.pos = c;
            d.w20 = 1;
            d.pos.w = 5627.9248f;
            d.b18 = t;
            d.b19 = 3;
            d.h1A = D_001EEB00[i]->h170;
            func_00443840(D_001EEB00[i], &d);
        }
    }
    f = func_00440978();
    func_00440CF8(&b, D_001E20E4, f, func_00440978());
    {
        Q_39A1D8 q0, q1, q2;
        __asm__("lqc2 %0, %1" : "=j"(q0) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q2) : "j"(q0), "j"(q1));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(q2));
    }
    if (func_003F8448(&obj->pos, &b, 0, obj, 0)) {
        b = D_001EAAA0;
    }
    func_0039AA18(obj, &b, 5);
    func_0039ACB0(obj);
    func_004026A0(func_0039A510, obj);
    } else {
        s32 k = D_001DE130;
        if (k > 0) {
            i = 0;
            do {
                D_002A1EF0[i].f9C = 0;
                i++;
            } while (--k != 0);
        }
        func_00436220(obj);
    }
}
/* localdecomp:end func_0039A1D8 */
