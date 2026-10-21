#include "common.h"

/* localdecomp:start func_0034C870 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} R_34C870;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0x78];
    s32 i98;
} T_34C870;
typedef struct {
    f32 a[3];
    f32 pad0C;
    f32 b[3];
    f32 pad1C;
    u128_t p20;
    u128_t p30;
    u128_t p40;
    u128_t p50;
    f32 r60[3];
    f32 s6C[3];
    f32 m78[3];
    f32 r84[3];
    f32 s90[3];
    f32 m9C[3];
    s32 iA8;
    void *owner;
    T_34C870 *tB0;
    T_34C870 *tB4;
    s32 iB8;
    s32 iBC;
    s32 iC0;
    s32 iC4;
    f32 fC8;
    s32 *pCC;
} E_34C870;
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[0x14];
} H_34C870;

extern E_34C870 D_0027FBA0[];
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern R_34C870 *func_00440728(T_34C870 *);
extern void func_0044DF40(void *, f32 *, s32);
extern void func_0040BE90(f32 *, f32 *, f32);
extern void func_0040BE68(u128_t *, u128_t *, u128_t *, f32);
extern s32 func_0040BA90(s32 *);
extern void func_0040C0F0(f32 *, f32 *, f32);
extern void func_00443628(H_34C870 *, u8 *, s32, f32 *, f32);
extern void func_00443840(T_34C870 *, H_34C870 *);
extern void func_0034D600(u128_t *, s32, s32);

void func_0034C870(u8 *obj) {
    f32 v[4] __attribute__((aligned(16)));
    H_34C870 h;
    u128_t tA[1];
    u128_t tB[1];
    u128_t tC[1];
    s32 i;

    for (i = 0; i < 48; i++) {
        E_34C870 *e = &D_0027FBA0[i];
        R_34C870 *r;

        if (e->owner != obj) {
            continue;
        }
        e->p20 = e->p40;
        if (e->tB4 != 0) {
            r = func_00440728(e->tB4);
            if (r != 0) {
                func_0044DF40((u8 *)e->tB4 + 16, v, 1);
                func_0040BE90(v, v, r->f10);
                __asm__ __volatile__("lqc2 $vf1, %0" : : "m"(*(u128_t *)v) : "memory");
                __asm__ __volatile__(
                    "sqc2 $vf1, %0\n"
                    "lqc2 $vf2, %2\n"
                    "lqc2 $vf1, %3\n"
                    "sqc2 $vf2, %1\n"
                    "lqc2 $vf2, %0\n"
                    "vadd.xyz $vf1, $vf2, $vf1\n"
                    "sqc2 $vf1, %4\n"
                    "lqc2 $vf1, %4\n"
                    "lqc2 $vf2, %1\n"
                    "vadd.xyz $vf1, $vf1, $vf2\n"
                    "sqc2 $vf1, %2\n"
                    : : "m"(*tC), "m"(*tA), "m"(e->p20), "m"(e->tB4->pos), "m"(*(u128_t *)v) : "memory");
            } else {
                e->p20 = e->tB4->pos;
            }
        }
        if (e->iB8 != 0) {
            e->r60[0] = func_0040CEC8(e->r60[0], e->s6C[0] * 100.0f);
            e->r60[1] = func_0040CEC8(e->r60[1], e->s6C[1] * 100.0f);
            e->r60[2] = func_0040CEC8(e->r60[2], e->s6C[2] * 100.0f);
            e->r84[0] = func_0040CEC8(e->r84[0], e->s90[0] * 100.0f);
            e->r84[1] = func_0040CEC8(e->r84[1], e->s90[1] * 100.0f);
            e->r84[2] = func_0040CEC8(e->r84[2], e->s90[2] * 100.0f);
        } else {
            e->r60[0] = func_0040CEC8(e->r60[0], e->s6C[0]);
            e->r60[1] = func_0040CEC8(e->r60[1], e->s6C[1]);
            e->r60[2] = func_0040CEC8(e->r60[2], e->s6C[2]);
            e->r84[0] = func_0040CEC8(e->r84[0], e->s90[0]);
            e->r84[1] = func_0040CEC8(e->r84[1], e->s90[1]);
            e->r84[2] = func_0040CEC8(e->r84[2], e->s90[2]);
        }
        e->a[0] = func_0040C3C8(e->r60[0]) * e->m78[0];
        e->a[1] = func_0040C3E0(e->r60[1]) * e->m78[1];
        e->a[2] = -func_0040C3E0(e->r60[2]) * e->m78[2];
        e->b[0] = func_0040C3C8(e->r84[0]) * e->m9C[0];
        e->b[1] = func_0040C3E0(e->r84[1]) * e->m9C[1];
        e->b[2] = -func_0040C3E0(e->r84[2]) * e->m9C[2];
        e->p30 = e->p50;
        if (e->tB0 != 0) {
            r = func_00440728(e->tB0);
            if (r != 0) {
                func_0044DF40((u8 *)e->tB0 + 16, v, 1);
                func_0040BE90(v, v, r->f10);
                __asm__ __volatile__("lqc2 $vf1, %0" : : "m"(*(u128_t *)v) : "memory");
                __asm__ __volatile__(
                    "sqc2 $vf1, %0\n"
                    "lqc2 $vf2, %2\n"
                    "lqc2 $vf1, %3\n"
                    "sqc2 $vf2, %1\n"
                    "lqc2 $vf2, %0\n"
                    "vadd.xyz $vf1, $vf2, $vf1\n"
                    "sqc2 $vf1, %4\n"
                    "lqc2 $vf1, %4\n"
                    "lqc2 $vf2, %1\n"
                    "vadd.xyz $vf1, $vf1, $vf2\n"
                    "sqc2 $vf1, %2\n"
                    : : "m"(*tC), "m"(*tB), "m"(e->p30), "m"(e->tB0->pos), "m"(*(u128_t *)v) : "memory");
            } else {
                e->p30 = e->tB0->pos;
            }
        }
        func_0040BE68(&e->p30, &e->p20, &e->p30, 1.0f - (f32)e->iB8 / (f32)e->iBC);
        if (func_0040BA90(&e->iB8) == 0) {
            continue;
        }
        if (e->tB0->i98 != 0 && e->iC0 == 0 && e->iC4 != 0) {
            {
                u128_t x, y;
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(e->p30));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e->p20));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
                __asm__("sqc2 %1, %0" : "=m"(*(u128_t *)v) : "j"(y));
            }
            func_0040C0F0(v, v, 0.033333335f);
            {
                f32 f = e->fC8;
                *(s32 *)(obj + 184) = e->pCC[8];
                func_00443628(&h, obj, 0x410000, v, f);
            }
            h.b18 = 5;
            h.h1A = *(u16 *)(obj + 170);
            h.b19 = 3;
            func_00443840(e->tB0, &h);
            e->iC0 = 1;
            func_0034D600(&e->p30, 10, 1);
        }
        if (func_0040BA90(&e->iA8) != 0) {
            e->owner = 0;
        }
    }
}
/* localdecomp:end func_0034C870 */
