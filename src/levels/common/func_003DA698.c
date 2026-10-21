#include "common.h"

/* localdecomp:start func_003DA698 */
typedef int s128 __attribute__((mode(TI)));

extern s32 D_001DF538;
extern s32 D_001DF53C;
extern s32 D_001DF568;
extern s32 D_001DF56C;
extern s32 D_001DFBC0[];
extern u8 *func_00435E70(s32, s32);
extern f32 func_0040BF68(f32 *);
extern f32 func_0040C490(f32, f32);
extern void func_0040C638(u8 *, u8 *);
extern f32 func_0040BF38(f32 *);
extern s32 func_00440878(s32, s32);
extern void func_00441FB8(u8 *, s32, s32);
extern void func_00439610(u8 *);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))
#define PTR(p, o) (*(u8 **)((p) + (o)))

u8 *func_003DA698(u8 *a0, s32 a1, s128 *a2, f32 *a3, f32 f) {
    u8 *o;
    u8 *q;
    s32 t;
    s32 n;
    s32 c;

    o = func_00435E70(7556, 128);
    if (o != 0) {
        q = PTR(o, 104);
        PTR(o, 184) = a0;
        S32(q, 24) = a1;
        U8(o, 48) = 255;
        S16(o, 50) = 128;
        U8(o, 49) = 1;
        F32(o, 44) = F32(PTR(o, 36), 36) * 0.75f;
        *(s128 *)(o + 16) = *a2;
        F32(o, 244) = -func_0040C490(func_0040BF68(a3), a3[2]);
        F32(o, 248) = func_0040C490(a3[0], a3[1]);
        func_0040C638(o + 192, o + 240);
        *(s128 *)q = *(s128 *)a3;
        F32(q, 32) = func_0040BF38(a3);
        F32(q, 16) = f;
        if (S32(q, 24) != 0) {
            S32(q, 20) = D_001DF538 * 2;
        } else {
            S32(q, 20) = func_00440878(D_001DF53C, D_001DF538);
        }
        t = D_001DFBC0[0];
        n = t + D_001DF56C;
        c = n < D_001DF568;
        S32(q, 40) = -1;
        S32(q, 28) = 0;
        if (c) {
            D_001DF568 = -1;
        }
        if (D_001DF568 < t) {
            S32(q, 36) = 1;
            D_001DF568 = n;
        } else {
            S32(q, 36) = 0;
        }
        func_00441FB8(o, 1, -1);
        func_00439610(o);
    }
    return o;
}
/* localdecomp:end func_003DA698 */
