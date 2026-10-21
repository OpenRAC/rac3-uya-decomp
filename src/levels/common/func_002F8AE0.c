#include "common.h"

/* localdecomp:start func_002F8AE0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_2F8AE0;
struct O_2F8AE0;
typedef struct {
    V4_2F8AE0 v0;
    V4_2F8AE0 v16;
    V4_2F8AE0 v32;
    V4_2F8AE0 v48;
    V4_2F8AE0 v64;
    V4_2F8AE0 v80;
    s32 i96;
    struct O_2F8AE0 *p100;
    void *p104;
    u8 b108;
    u8 b109;
} S_2F8AE0;
typedef struct O_2F8AE0 {
    u8 pad0[16];
    V4_2F8AE0 pos;
    u8 b32;
    u8 pad33[71];
    S_2F8AE0 *s;
    u8 pad108[84];
    V4_2F8AE0 v192;
    u8 pad208[48];
} O_2F8AE0;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 pad[16];
} E_2F8AE0;
typedef struct {
    V4_2F8AE0 v[2];
} T_2F8AE0;
extern T_2F8AE0 D_0026E0C0[];
extern O_2F8AE0 *D_001E009C;
extern s32 D_001DFBC0;
extern E_2F8AE0 D_002BE748[];
extern s32 func_002F9520(O_2F8AE0 *);
extern void func_0040C9F8(void *, void *, void *);
extern void func_00449720(O_2F8AE0 *, O_2F8AE0 *, S_2F8AE0 *, void *, void *, void *);
extern void func_00443FD8(void *, void *);
extern void func_0040CBC0(void *, void *, void *);
extern s32 func_003F9498(void *, s32, void *, f32);
extern void func_00441FB8(void *, s32, s32);
extern V4_2F8AE0 *func_00449388(O_2F8AE0 *);
extern void func_0040CB80(void *, void *);
extern void func_0040BE90(void *, void *, f32);
void func_002F8AE0(O_2F8AE0 *obj, V4_2F8AE0 *out1, V4_2F8AE0 *out2) {
    V4_2F8AE0 t0;
    V4_2F8AE0 v16;
    V4_2F8AE0 v32;
    V4_2F8AE0 v48;
    V4_2F8AE0 v64;
    V4_2F8AE0 v80;
    V4_2F8AE0 tmp;
    S_2F8AE0 *s = obj->s;
    s32 hit;
    V4_2F8AE0 *r;
    E_2F8AE0 *e;

    func_0040C9F8(&s->v80, &D_0026E0C0[func_002F9520(obj)].v[s->b109 & 1], &s->v80);
    func_0040C9F8(&s->v16, &s->v16, &s->v48);
    func_0040C9F8(&v32, &s->v80, &s->v16);
    if (s->p100 != 0) {
        __asm__("sq $0, %0" : "=m"(v64));
        func_00449720(obj, s->p100, s, &v64, &v16, &v64);
        func_00443FD8(&v80, &v64);
        func_0040C9F8(&v32, &v32, &v80);
        func_0040CBC0(&v48, &s->v64, &v80);
        if (obj->b32 == 3) {
            hit = 0;
            if (s->p100 == 0 || s->p100->b32 == 254 || s->p100->b32 == 253) {
                hit = 1;
            } else if ((D_001DFBC0 + (obj - D_001E009C)) % 10 == 0) {
                hit = func_003F9498(&obj->pos, 34, obj, 0.25f) == 0;
            }
            if (hit) {
                func_00441FB8(obj, 1, -1);
                {
                    f32 one = 1.0f;
                    __asm__ __volatile__("sq $0, %0" : "=m"(s->v32));
                    s->v32.w = one;
                }
                r = func_00449388(s->p100);
                if (r != 0) {
                    s->v48 = r[1];
                } else {
                    __asm__ __volatile__("sq $0, %0" : "=m"(s->v48));
                }
                s->p100 = 0;
            }
        }
    } else {
        v16 = s->v0;
        v48 = s->v64;
    }
    func_0040CB80(&v32, &obj->v192);
    e = &D_002BE748[func_002F9520(obj)];
    func_0040BE90(&obj->pos, &v48, e->f4);
    func_0040BE90(&t0, &obj->v192, e->f8);
    __asm__ __volatile__(
        "lqc2 $vf1, %0\n"
        "lqc2 $vf2, %1\n"
        "vadd.xyz $vf2, $vf2, $vf1\n"
        "lqc2 $vf1, %2\n"
        "sqc2 $vf1, %3\n"
        "sqc2 $vf2, %1\n"
        "lqc2 $vf1, %1\n"
        "lqc2 $vf2, %3\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %1\n"
        : : "m"(t0), "m"(obj->pos), "m"(v16), "m"(tmp) : "memory");
    if (out1 != 0) {
        *out1 = v16;
    }
    if (out2 != 0) {
        *out2 = v32;
    }
}
/* localdecomp:end func_002F8AE0 */
