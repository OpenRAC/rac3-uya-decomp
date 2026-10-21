#include "common.h"

/* localdecomp:start func_004B66E0 */
typedef int Q_4B66E0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4B66E0;
typedef struct {
    V4_4B66E0 v0;
    V4_4B66E0 pos;
    u8 pad32[20];
    u16 h52;
    u8 pad54[10];
    u8 b64;
    u8 b65;
    u8 pad66[2];
    f32 f68;
    u8 pad72[25];
    u8 b97;
    u8 pad98;
    u8 b99;
    u8 pad100[4];
    V4_4B66E0 *p104;
    u8 pad108[3];
    u8 b111;
    u8 pad112[58];
    s16 h170;
    u8 pad172[8];
    s16 h180;
    u8 pad182[58];
    V4_4B66E0 v240;
} O_4B66E0;
typedef struct {
    u8 pad0[52];
    s32 i52;
    s32 i56;
    s32 i60;
    s16 h64;
    u8 pad66[2];
    s16 h68;
    u8 pad70[2];
    s16 h72;
    u8 pad74[22];
    s8 b96;
    u8 pad97[319];
    O_4B66E0 *objs[1];
} S_4B66E0;
typedef struct {
    u8 pad0[100];
    u8 b100;
} E_4B66E0;
typedef struct {
    u8 pad0[420];
    s32 i420;
} P_4B66E0;
extern S_4B66E0 D_001E6E00;
extern E_4B66E0 D_001EA840;
extern f32 D_001DF9D0;
extern s32 D_001D4D40;
extern P_4B66E0 *D_001D52FC;
extern s32 D_00143950[];
extern s16 D_001CCFD4[];
extern void func_00417BF8(void *);
extern s32 func_00417C28(void *);
extern void func_00457360(s32, s32);
extern void func_004B51C0(void);
extern void func_00420CD8(void);
extern void func_0045B2B8(void);
extern void func_004A76F0(void);
extern void func_004DE348(void);
extern void func_0045E788(void);
extern void func_004450C0(f32 *, f32, f32);
extern void func_0045B9C8(void);
extern void func_0045CA60(s32);
extern void func_00429740(void);
extern void func_004296B0(s32);
extern s32 func_004B6518(void);
extern void func_00436350(O_4B66E0 *);
extern void func_0040BE90(void *, void *, f32);
extern void func_00439610(O_4B66E0 *);
extern f32 func_0040BFB0(void *, void *);
extern void func_0040BE68(void *, void *, void *, f32);
extern void func_00444188(O_4B66E0 *);
extern void func_0050EA58(O_4B66E0 *, s32);
extern void func_004DEBC0(O_4B66E0 *);
extern void func_004214C0(void);
extern void func_004A57D8(void);
extern void func_00422048(void);
extern void func_00437AB8(void);
extern void func_004B5258(void);

void func_004B66E0(void) {
    V4_4B66E0 a, b;
    Q_4B66E0 qa, qb;
    s32 cond, done, i, sel, m, lim, k;
    O_4B66E0 *o;
    V4_4B66E0 *p;
    f32 d, t;

    if (D_001E6E00.b96 != 0) {
        return;
    }
    if (D_001E6E00.h64 == 0) {
        func_00417BF8(&D_001EA840);
        D_001E6E00.b96 = 1;
        func_00457360(0, 0);
        return;
    }
    if (D_001E6E00.h64 < D_001E6E00.i52 + 15) {
        s32 q = D_001E6E00.h64 - 15;
        D_001DF9D0 = (f32)(D_001E6E00.i52 - q) * 0.06666667f;
    }
    func_004B51C0();
    func_00420CD8();
    func_0045B2B8();
    func_004A76F0();
    func_004DE348();
    func_0045E788();
    D_001E6E00.i56++;
    D_001E6E00.i52++;
    if (D_001E6E00.i52 < 30) {
        func_004450C0(&D_001DF9D0, 0.0f, 0.0400000028f);
        if (1.0f < D_001DF9D0) {
            D_001DF9D0 = 1.0f;
        }
    }
    if (D_001E6E00.i52 >= D_001E6E00.h72) {
        func_0045B9C8();
    }
    cond = 0;
    done = D_001E6E00.i52 >= D_001E6E00.h64;
    if (D_001E6E00.i52 >= 18 && D_001DF9D0 == 0.0f && !(D_001D4D40 & 0x80)) {
        m = D_001D4D40 & ~0xC0;
        if (m != 2) {
            if (m == 0 && (D_001D52FC->i420 & 0x9FF)) {
                cond = 1;
            } else {
                s32 t = D_001D52FC->i420 & 0x800;
                cond = t != 0;
            }
        }
    }
    if (cond) {
        D_001D4D40 &= ~0x80;
        D_001EA840.b100 = 1;
        func_00417BF8(&D_001EA840);
        D_001E6E00.b96 = 1;
        func_00457360(0, 0);
    } else if (done) {
        D_001D4D40 &= ~0x80;
        D_001E6E00.b96 = 1;
        if (func_00417C28(&D_001EA840) == 0) {
            func_00457360(0, 0);
        }
    } else {
        lim = 96;
        if (D_00143950[0]) {
            lim = 80;
        }
        if (D_001E6E00.i56 >= lim) {
            D_001E6E00.i60++;
            if (D_001CCFD4[0] != 0) {
                func_0045CA60(1);
            }
            func_00429740();
            func_004296B0(D_001E6E00.i60 + 1);
        }
        sel = func_004B6518();
        for (i = 0; i < D_001E6E00.h68; i++) {
            o = D_001E6E00.objs[i];
            k = D_001E6E00.i56 >> 1;
            o->b65 = k + 1;
            o->b64 = k;
            func_00436350(o);
            o->f68 = (f32)(D_001E6E00.i56 & 1) * 0.5f;
            if (sel && (D_001E6E00.i56 & 1) && o->h180 == 0) {
                o->f68 = 1.0f;
            }
            p = o->p104;
            func_0040BE90(&a, &p[o->b64], 1.0f - o->f68);
            func_0040BE90(&b, &p[o->b65], o->f68);
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(qa));
            o->b97 = 255;
            func_00439610(o);
            if (o->b99) {
                if (D_001E6E00.i60 != 0 && D_001E6E00.i56 < 16) {
                    d = func_0040BFB0(o, &o->v240);
                    if (d < 20.0f) {
                        t = (f32)D_001E6E00.i56 * 0.0625f;
                        func_0040BE68(o, &o->v240, o, t);
                        o->v0.w += d * (1.0f - t);
                    }
                } else {
                    o->v240 = o->v0;
                    o->h52 |= 0x100;
                }
            }
            if (o->b111) {
                func_00444188(o);
            }
            if (o->h170 == 0 || o->h170 == 3947) {
                func_0050EA58(o, 0);
            }
            if (o->h170 == 10 || o->h170 == 6601 || o->h170 == 4441 || o->h170 == 8043 ||
                o->h170 == 87 || o->h170 == 601 || o->h170 == 8043) {
                func_004DEBC0(o);
            }
        }
    }
    func_004214C0();
    func_004A57D8();
    func_00422048();
    func_00437AB8();
    func_004B5258();
}
/* localdecomp:end func_004B66E0 */
