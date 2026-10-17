#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern s32 D_001D673C;
extern void func_0044DF40(u8 *, Vec4 *, s32);
extern void func_0044E358(u8 *, Vec4 *, Vec4 *);
extern void func_00447748(u8 *, u8 *);
extern void func_00436220(u8 *);

void func_00301530(u8 *m) {
    Vec4 v;
    Vec4 mt[3];
    u8 *pv;
    s32 flag;

    flag = D_001D673C;

    pv = *(u8 **)(m + 104);
    *(f32 *)(m + 44) *= *(f32 *)pv;
    if (flag != 0) {
        func_0044DF40(m + 16, &v, 0);
        func_0044E358(m + 192, &v, mt);
        func_00447748(m + 192, m + 240);
    }
    m[35] -= pv[4];
    if (m[35] <= pv[4]) {
        func_00436220(m);
    }
}
