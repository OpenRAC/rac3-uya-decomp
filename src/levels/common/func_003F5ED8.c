#include "common.h"

/* localdecomp:start func_003F5ED8 */
typedef struct {
    f32 v[4];
} V4_003F5ED8;

extern void func_003F6478(u8 *self);
extern void func_003F62D8(u8 *self);
extern s32 func_003F6678(u8 *self);
extern void func_0040C0F0(void *a, void *b, f32 s);
extern void func_0040BF20(void *out, void *m, void *v);
extern void func_003F6CD0(u8 *self, void *a, void *b);
extern void func_0044DF40(void *a, void *b, s32 c);
extern s32 func_003F6DF0(void *a, void *b, void *c, f32 d, f32 e);
extern s32 func_004A7200(s32 a, s32 b, u8 *c);
extern void func_003F6988(u8 *self, s32 a, void *b);
extern void func_004A75E0(s32 a, void *b);
extern u8 D_001EAAC0[];

s32 func_003F5ED8(u8 *self) {
    V4_003F5ED8 a;
    V4_003F5ED8 b;
    u8 *v;
    u8 st;
    s32 idx;
    s32 h;

    v = *(u8 **)(self + 104);
    st = v[92];
    if (st >= 3) {
        return 1;
    }
    if (st != 0) {
        func_003F6478(self);
    } else {
        func_003F62D8(self);
    }
    idx = func_003F6678(self);
    if (idx != -1) {
        h = -1;
        func_0040C0F0(D_001EAAC0, D_001EAAC0, 1.0f);
        func_0040BF20(&a, D_001EAAC0, v);
        func_003F6CD0(self, v + 16, &a);
        func_0044DF40(self + 16, &b, 1);
        if (func_003F6DF0(v, D_001EAAC0, &b, *(f32 *)(v + 56), *(f32 *)(v + 60)) == 0) {
            if (v[94] != 255 && v[92] == 0) {
                h = func_004A7200(v[94], 0, self);
            }
            func_003F6988(self, idx, &b);
        } else if (v[94] != 255) {
            h = func_004A7200(v[94], 0, self);
        }
        if (h != -1) {
            func_004A75E0(h, v + 32);
        }
    }
    return 0;
}
/* localdecomp:end func_003F5ED8 */
