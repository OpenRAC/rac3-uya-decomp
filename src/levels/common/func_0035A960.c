#include "common.h"

typedef int u128_35A960 __attribute__((mode(TI)));

typedef struct {
    u128_35A960 a;
    u128_35A960 b;
    s32 active;
} S_35A960;

extern s32 func_004B77C8(u128_35A960 *, u128_35A960 *, f32);
extern u32 func_004B7538(void);
extern s32 func_004B7618(u32, s32, s32, s32);
extern void func_004B7558(u32, f32);
extern void func_004B75B0(u32, u128_35A960 *, u128_35A960 *);
extern void func_004B7678(u32);

void func_0035A960(s32 arg0, S_35A960 *p, S_35A960 *q, u32 *h) {
    u128_35A960 v[2];
    u32 n;

    if (p->active == 1 || q->active == 1) {
        if (p->active == 1) {
            v[0] = p->a;
            if (q->active == 1) {
                v[1] = q->b;
            } else {
                v[1] = p->b;
            }
        } else {
            v[0] = q->a;
            v[1] = q->b;
        }
        if (*h == 0xFFFFFFFF) {
            if (func_004B77C8(&v[0], &v[1], 24.0f) == 0) {
                n = func_004B7538();
                *h = n;
                func_004B7618(n, 0, arg0, 6455);
                func_004B7558(*h, 24.0f);
                func_004B75B0(*h, &v[0], &v[1]);
            }
        } else if (func_004B77C8(&v[0], &v[1], 24.0f) == 0) {
            func_004B75B0(*h, &v[0], &v[1]);
        } else {
            func_004B7678(*h);
            *h = 0xFFFFFFFF;
        }
    } else if (*h != 0xFFFFFFFF) {
        func_004B7678(*h);
        *h = 0xFFFFFFFF;
    }
}
