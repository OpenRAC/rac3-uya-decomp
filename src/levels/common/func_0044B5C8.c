#include "common.h"

/* localdecomp:start func_0044B5C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_44B5C8;
typedef struct {
    u8 pad0[32];
    u8 b20;
} T_44B5C8;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[14];
    V4_44B5C8 v10;
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2C[20];
    f32 f40;
    f32 f44;
    f32 f48;
    u8 pad4C[4];
    f32 f50;
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    V4_44B5C8 v60;
    f32 f70;
    u8 pad74[4];
    T_44B5C8 *p78;
} S_44B5C8;
extern void func_004373D8(void *, void *);
extern void func_00437350(void *, void *, void *);
extern void func_004455F0(f32 *, f32 *, f32, f32, f32, f32, s32);
extern void func_00443FD8(void *, void *);
void func_0044B5C8(void *a, S_44B5C8 *s, void *c, f32 x, f32 y) {
    T_44B5C8 *t;
    f32 *q;
    f32 f;
    t = s->p78;
    if (t == 0) {
        s->p78 = a;
    } else if (t != a) {
        if (s->b1 != 0 && t->b20 < 0x7F) {
            func_004373D8(t, s);
        }
        s->b1 = 0;
        s->p78 = a;
    }
    if (s->v60.x == 0.0f && s->v60.y == 0.0f && s->v60.z == 0.0f && s->f70 == 1.0f && __builtin_fabsf(s->f40) < 0.005f && __builtin_fabsf(s->f44) < 0.005f && __builtin_fabsf(s->f48) < 0.005f) {
        if (s->b1 != 0) {
            func_004373D8(a, s);
        }
    } else {
        q = &s->f40;
        func_004455F0(q, &s->f50, s->v60.x, x, y, 0.0f, 0);
        func_004455F0(&s->f44, &s->f54, s->v60.y, x, y, 0.0f, 0);
        func_004455F0(&s->f48, &s->f58, s->v60.z, x, y, 0.0f, 0);
        if (s->b1 == 0) {
            func_00437350(a, c, s);
        }
        func_00443FD8(&s->v10, q);
        f = s->f70;
        __asm__ __volatile__("sq $0,%0" : "=m"(s->v60));
        s->f20 = f;
        s->f24 = f;
        s->f28 = f;
        s->f70 = 1.0f;
    }
}
/* localdecomp:end func_0044B5C8 */
