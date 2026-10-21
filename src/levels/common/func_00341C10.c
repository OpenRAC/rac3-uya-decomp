#include "common.h"

/* localdecomp:start func_00341C10 */
typedef int s128_00341C10 __attribute__((mode(TI)));

typedef union {
    s128_00341C10 q;
    f32 f[4];
} V_00341C10;

typedef struct {
    u8 a;
    u8 b;
    u8 pad[238];
} S_00341C10;

extern s32 D_001D6694;
extern s32 D_001DD29C;
extern u8 D_001A4BE0[];
extern u8 D_001425D6[];
extern S_00341C10 D_002C5640[];
extern f32 func_004C5828(void);
extern s32 func_00342FB0(f32 t);
extern void func_00437698(s32 a, s32 b, void *c);
extern void func_00341DA0(u8 *self);
extern void func_00342098(u8 *self);
extern void func_00342478(u8 *self);
extern void func_0040BE90(void *out, void *in, f32 s);
extern void func_0040BF20(void *out, void *a, void *b);
extern void func_0040C0F0(void *out, void *in, f32 s);
extern void func_00409A50(void *v, s32 a, s32 b, s32 c, s32 d, f32 e);

void func_00341C10(u8 *self) {
    V_00341C10 arr[4];
    V_00341C10 tmp;
    u8 *v;
    u8 *base;
    f32 t;

    if (D_001D6694 != 0) {
        return;
    }
    v = *(u8 **)(self + 104);
    if (func_00342FB0(func_004C5828()) == 0) {
        return;
    }
    if (D_001DD29C == 40) {
        return;
    }
    base = D_001A4BE0;
    func_00437698(*(s32 *)(base + 9664), 10, v + 48);
    func_00341DA0(self);
    func_00342098(self);
    func_00342478(self);
    if ((D_001425D6[0] + D_002C5640)->b < 2) {
        return;
    }
    t = *(f32 *)(v + 64) + 0.1f;
    *(f32 *)(v + 64) = t;
    if (7.0f <= t) {
        *(f32 *)(v + 64) = t - 7.0f;
    }
    arr[3].q = *(s128_00341C10 *)(v + 48);
    arr[3].f[3] = 1.0f;
    arr[0].q = *(s128_00341C10 *)(*(u8 **)(base + 9664) + 192);
    func_0040BE90(&tmp, base + 736, -1.0f);
    func_0040BF20(&arr[1], &arr[0], &tmp);
    func_0040C0F0(&arr[1], &arr[1], 1.0f);
    func_0040BF20(&arr[2], &arr[1], &arr[0]);
    func_00409A50(arr, 23, *(s32 *)(v + 8) | 0x1F000000, 10, 1, *(f32 *)(v + 64));
}
/* localdecomp:end func_00341C10 */
