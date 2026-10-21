#include "common.h"

/* localdecomp:start func_004DC480 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[14];
    u8 m16[16];
    f32 f32_;
    f32 f36;
    f32 f40;
    f32 f44;
    u128_t q48;
    f32 f64[4];
    f32 f80[4];
    union { u128_t q; f32 f[4]; } v96;
    union { u128_t q; f32 f[4]; } v112;
    f32 f128[4];
    union { u128_t q; f32 f[4]; } v144;
    s16 h160;
    s16 h162;
    f32 f164;
    f32 f168;
    f32 f172;
} S_4DC480;
extern u8 D_001A71C4[];
extern void *func_004DC420(s32);
extern void func_004373D8(void *, S_4DC480 *);
extern void func_004455F0(f32 *, f32 *, f32, f32, f32, f32, s32);
extern void func_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern void func_00437350(void *, s32, S_4DC480 *);
extern void func_00443FD8(void *, void *);
void func_004DC480(S_4DC480 *s) {
    void *o;
    s16 t;
    f32 z;
    f32 sc;

    o = func_004DC420(s->h162);
    if (o == 0) {
        return;
    }
    if (D_001A71C4[0] == 0) {
        t = s->h162;
        if (t == 4 || t == 2 || t == 6 || t == 7 || t == 3) {
            return;
        }
    } else if (s->h162 == 0) {
        return;
    }
    if (s->v96.f[0] == 0.0f && s->v96.f[1] == 0.0f && s->v96.f[2] == 0.0f &&
        s->v144.f[0] == 0.0f && s->v144.f[1] == 0.0f && s->v144.f[2] == 0.0f &&
        fabsf(s->v112.f[0]) < 0.003f && fabsf(s->v112.f[1]) < 0.003f && fabsf(s->v112.f[2]) < 0.003f &&
        s->f172 == 1.0f &&
        fabsf(s->f64[0]) < 0.005f && fabsf(s->f64[1]) < 0.005f && fabsf(s->f64[2]) < 0.005f) {
        if (s->b1 != 0) {
            func_004373D8(o, s);
        }
    } else {
        z = 0.0f;
        func_004455F0(&s->f64[0], &s->f80[0], s->v96.f[0], s->f164, s->f168, z, 2);
        func_004455F0(&s->f64[1], &s->f80[1], s->v96.f[1], s->f164, s->f168, z, 2);
        func_004455F0(&s->f64[2], &s->f80[2], s->v96.f[2], s->f164, s->f168, z, 2);
        func_00445168(&s->v112.f[0], &s->f128[0], s->v144.f[0], s->f164, s->f168, z);
        func_00445168(&s->v112.f[1], &s->f128[1], s->v144.f[1], s->f164, s->f168, z);
        func_00445168(&s->v112.f[2], &s->f128[2], s->v144.f[2], s->f164, s->f168, z);
        if (s->b1 == 0) {
            func_00437350(o, s->h160, s);
        }
        func_00443FD8(s->m16, s->f64);
        sc = s->f172;
        s->q48 = s->v112.q;
        s->f32_ = sc;
        s->f36 = sc;
        s->f40 = sc;
    }
    __asm__("sq $0,%0" : "=m"(s->v144.q));
    __asm__("sq $0,%0" : "=m"(s->v96.q));
    s->f172 = 1.0f;
}
/* localdecomp:end func_004DC480 */
