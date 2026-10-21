#include "common.h"

/* localdecomp:start func_00333758 */
typedef struct {
    u8 *(*f0)(u8 *);
    u8 pad4[140];
    s32 (*f90)(u8 *);
    u8 *(*f94)(u8 *);
} S_333758;

extern u8 *D_001E009C;
extern S_333758 *func_00438488(s32, s32, s32);
extern void func_00335C70(u8 *, s32);
extern void func_00441FB8(u8 *, s32, s32);
extern void func_00329AA8(u8 *, u8 *);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define U16(p, o) (*(u16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define PTR(p, o) (*(u8 **)((p) + (o)))

s32 func_00333758(u8 *a0) {
    u8 *p;
    S_333758 *t;
    u8 *m;
    s32 n;
    u8 *b;

    if (U8(a0, 32) == 0) {
        u8 *q = PTR(a0, 104);
        n = S32(q, 48);
        PTR(q, 44) = q + 48;
        S32(q, 80) = -1;
        S32(q, 96) = 0;
        S32(q, 100) = 0;
        S32(q, 104) = 0;
        S32(q, 84) = 0;
        S32(q, 88) = 0;
        *(s8 *)(q + 92) = -1;
        U8(q, 93) = 0;
        U8(q, 94) = 0;
        U8(q, 95) = 0;
        if (n > 0) {
            S32(q, 48) = -1;
            U8(q, 62) = 3;
            func_00335C70(a0, 0);
        } else {
            func_00441FB8(a0, 1, -1);
        }
        return 1;
    }
    if (U8(a0, 32) != 1) {
        return 0;
    }
    p = PTR(a0, 104);
    t = func_00438488(S32(p, 64), 4, 156);
    PTR(a0, 184) = D_001E009C + (S32(p, 68) << 8);
    m = t->f0(a0);
    b = D_001E009C;
    S32(p, 80) = (m - b) >> 8;
    func_00329AA8(b + (S32(p, 68) << 8), a0);
    S32(p, 76) = -1;
    if (PTR(a0, 184) != 0 && m != 0) {
        if (U8(PTR(PTR(a0, 184), 104), 144) != 0 && t->f90 != 0) {
            t->f90(m);
        }
        U16(p, 122) = U16(t->f94(m), 52);
    }
    func_00441FB8(a0, 2, -1);
    return 1;
}
/* localdecomp:end func_00333758 */
