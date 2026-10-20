#include "common.h"

typedef struct {
    u8 a;
    u8 b;
    u8 pad[238];
} S_002C5640;

typedef struct {
    u8 a[16];
    u8 b[48];
} S_001DC604;

extern s32 func_0013D3E0(void);
extern void func_00305620(void *a, void *b);
extern s32 func_00440878(s32 lo, s32 hi);
extern f32 func_004408C0(f32 lo, f32 hi);
extern void func_00470258(void *a, void *b, s32 c, s32 d, f32 e, s32 f, s32 g);
extern void func_00463938(void *a, void *b, s32 c, f32 d, f32 e);
extern S_001DC604 *D_001DC604;
extern u8 D_001425D1[];
extern S_002C5640 D_002C5640[];

void func_00304888(u8 *self) {
    s32 *p;
    s32 n;
    S_001DC604 *q;
    s32 c;
    f32 f;

    p = *(s32 **)(self + 104);
    n = p[18] - (p[17] - 2);
    if (n < 0) {
        n += 35;
    }
    if (func_0013D3E0() % 7 == 0) {
        func_00305620(self, &D_001DC604[n]);
    }
    if (func_0013D3E0() % 22 != 0) {
        return;
    }
    if ((D_001425D1[0] + D_002C5640)->b >= 4) {
        if (func_0013D3E0() & 1) {
            q = &D_001DC604[n];
            c = (func_00440878(64, 100) << 16) | 0x64004040;
            f = func_004408C0(0.1f, 0.2f) * 210000.0f;
            func_00470258(q, q->b, c, 0xFF0A0A, f, (s16)func_00440878(20, 80), 0);
        }
    } else {
        func_00463938(&D_001DC604[n], D_001DC604[n].b, 0, -1.0f, 0.0f);
    }
}
