#include "common.h"

/* localdecomp:start func_0030A3D0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} R_30A3D0;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0x78];
    s32 i98;
} T_30A3D0;
typedef struct {
    f32 a[3];
    f32 pad0C;
    f32 b[3];
    f32 pad1C;
    u128_t p20;
    u128_t p30;
    f32 r40[3];
    f32 s4C[3];
    f32 m58[3];
    f32 r64[3];
    f32 s70[3];
    f32 m7C[3];
    s32 i88;
    void *owner;
    T_30A3D0 *target;
    s32 i94;
    s32 i98;
    s32 i9C;
} E_30A3D0;
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[0x14];
} H_30A3D0;
typedef struct {
    u8 pad0[0x70];
    f32 f70;
    u8 pad74[0x7C];
} G_30A3D0;
typedef struct {
    u8 pad0[0x54];
    s32 i54;
} M_30A3D0;

extern E_30A3D0 D_0026FDB0[];
extern u8 D_001425C0[];
extern G_30A3D0 D_002C5640[];
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern R_30A3D0 *func_00440728(T_30A3D0 *);
extern void func_0044E010(T_30A3D0 *, f32 *, s32);
extern void func_0040BE90(f32 *, f32 *, f32);
extern void func_0040BE68(u128_t *, u128_t *, u128_t *, f32);
extern s32 func_0040BA90(s32 *);
extern void func_0040C0F0(f32 *, f32 *, f32);
extern void func_00443628(H_30A3D0 *, u8 *, s32, f32 *, f32);
extern s32 func_00443840(T_30A3D0 *, H_30A3D0 *);
extern void func_0031AC38(T_30A3D0 *, s32, s32);
extern void func_004A7200(s32, s32, u8 *);
extern void func_0030BC80(u128_t *, f32 *, s32, s32);

void func_0030A3D0(u8 *obj) {
    f32 v[4] __attribute__((aligned(16)));
    H_30A3D0 h;
    M_30A3D0 *m = *(M_30A3D0 **)(obj + 104);
    s32 i;

    for (i = 0; i < 30; i++) {
        E_30A3D0 *e = &D_0026FDB0[i];
        R_30A3D0 *r;
        u128_t *p;

        if (e->owner != obj) {
            continue;
        }
        e->p20 = *(u128_t *)(obj + 16);
        if (e->i94 != 0) {
            e->r40[0] = func_0040CEC8(e->r40[0], e->s4C[0] * 100.0f);
            e->r40[1] = func_0040CEC8(e->r40[1], e->s4C[1] * 100.0f);
            e->r40[2] = func_0040CEC8(e->r40[2], e->s4C[2] * 100.0f);
            e->r64[0] = func_0040CEC8(e->r64[0], e->s70[0] * 100.0f);
            e->r64[1] = func_0040CEC8(e->r64[1], e->s70[1] * 100.0f);
            e->r64[2] = func_0040CEC8(e->r64[2], e->s70[2] * 100.0f);
        } else {
            e->r40[0] = func_0040CEC8(e->r40[0], e->s4C[0]);
            e->r40[1] = func_0040CEC8(e->r40[1], e->s4C[1]);
            e->r40[2] = func_0040CEC8(e->r40[2], e->s4C[2]);
            e->r64[0] = func_0040CEC8(e->r64[0], e->s70[0]);
            e->r64[1] = func_0040CEC8(e->r64[1], e->s70[1]);
            e->r64[2] = func_0040CEC8(e->r64[2], e->s70[2]);
        }
        e->a[0] = func_0040C3C8(e->r40[0]) * e->m58[0];
        e->a[1] = func_0040C3E0(e->r40[1]) * e->m58[1];
        e->a[2] = -func_0040C3E0(e->r40[2]) * e->m58[2];
        e->b[0] = func_0040C3C8(e->r64[0]) * e->m7C[0];
        e->b[1] = func_0040C3E0(e->r64[1]) * e->m7C[1];
        e->b[2] = -func_0040C3E0(e->r64[2]) * e->m7C[2];
        if (e->target != 0) {
            r = func_00440728(e->target);
            if (r != 0) {
                func_0044E010(e->target, v, 1);
                func_0040BE90(v, v, r->f10);
                __asm__ __volatile__(
                    "lqc2 $vf1, 0(%0)\n"
                    "lqc2 $vf2, 16(%1)\n"
                    "vadd.xyz $vf1, $vf1, $vf2\n"
                    "sqc2 $vf1, 48(%2)\n"
                    : : "r"(v), "r"(e->target), "r"(e) : "memory");
            } else {
                e->p30 = e->target->pos;
            }
            func_0040BE68(&e->p30, &e->p20, &e->p30, 1.0f - (f32)e->i94 / (f32)e->i98);
        }
        if (func_0040BA90(&e->i94) == 0) {
            continue;
        }
        if (e->target->i98 != 0 && e->i9C == 0) {
            {
                /* PROVISIONAL, VU0 j-constraint form */
                u128_t x, y, r;
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(e->p30));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e->p20));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
                __asm__("sqc2 %1, %0" : "=m"(*(u128_t *)v) : "j"(r));
            }
            func_0040C0F0(v, v, 0.033333335f);
            p = &e->p30;
            func_00443628(&h, obj, 0x410000, v, ((G_30A3D0 *)(D_001425C0[16] * 240 + (s32)D_002C5640))->f70);
            h.b18 = 1;
            h.b19 = 3;
            h.h1A = *(u16 *)(obj + 170);
            func_00443840(e->target, &h);
            func_0031AC38(e->target, 160, *(s32 *)(obj + 184));
            func_004A7200(1, 0, obj);
            func_0040C0F0(v, v, -1.0f);
            func_0030BC80(p, v, 9, 0xFF0000);
            e->i9C = 1;
        }
        if (func_0040BA90(&e->i88) != 0) {
            e->owner = 0;
            m->i54--;
        }
    }
}
/* localdecomp:end func_0030A3D0 */
