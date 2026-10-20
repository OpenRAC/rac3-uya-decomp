#include "common.h"

typedef void (*Fn_00335328)(s32, s32, s32);

extern s32 *D_0021F740[];
extern s32 func_00458AE0(s32, s32);
extern void func_00458E48(s32, s32 *, s32, s32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))

s32 func_00335328(u8 *a0, u8 *a1, s32 a2, u8 *a3, s32 t0, u8 *t1, u8 *t2) {
    s32 s3;
    s32 *p;
    u8 type;
    if (S32(t1, 108) != -1 && U8(a1, 94) == 0) {
        s3 = S16(a3, 600);
        if (func_00458AE0(a2, S32(t1, 108)) != 0) {
            if ((u32)(U8(t1, 19) - 3) < 2) {
                p = D_0021F740[S32(t1, 108)];
                if (S16(a3, 602) == 0) {
                    func_00458E48(a2, p, *p - 1, 0);
                } else {
                    func_00458E48(a2, p, 0, 0);
                }
            } else {
                U8(a1, 94) = 1;
                U8(a0, 188) = 1;
            }
            if (U8(t1, 19) == 4) {
                U8(a0, 188) = 1;
            }
        } else {
            type = U8(t1, 19);
            if (type == 2 || type == 4) {
                if (S16(a3, 600) != s3) {
                    U8(a0, 188) = 1;
                }
            }
        }
    }
    if (U8(t1, 151) == 0) {
        (*(Fn_00335328 *)(t2 + 36))(a2, 0, 10);
    } else {
        (*(Fn_00335328 *)(t2 + 32))(a2, 0, 10);
    }
    return 0;
}
