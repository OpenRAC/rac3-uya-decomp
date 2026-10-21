#include "common.h"

/* localdecomp:start func_003351A0 */
typedef int Q_3351A0 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x20];
    s32 (*f20)(void *, s32, s32);
    s32 (*f24)(void *, s32, s32);
} VT_3351A0;
extern void func_00334198(void *, void *);
extern f32 func_0040BFE8(void *, void *);
extern void func_00333D30(void *, void *, f32);
extern s32 func_00457440(void *, void *);

s32 func_003351A0(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 a4, u8 *a5, VT_3351A0 *a6) {
    Q_3351A0 q;
    u8 *t;
    u8 *r;

    func_00334198(a2, a3);
    q = *(Q_3351A0 *)(*(u8 **)(a3 + 0x440) + 0x10);
    if (func_0040BFE8(a3 + 0x410, &q) > 1.0f) goto reset;
    r = a2 + 0x10;
    if (func_0040BFE8(r, a3 + 0x3F0) < 0.75f) goto reset;
    if (func_0040BFE8(r, a1 + 0x80) > 4.0f) {
reset:
        t = *(u8 **)(a3 + 0x440);
        *(Q_3351A0 *)(a3 + 0x3F0) = *(Q_3351A0 *)(t + 0x10);
        *(Q_3351A0 *)(a3 + 0x410) = *(Q_3351A0 *)(t + 0x10);
        func_00333D30(a2, a3, 12.0f);
        *(Q_3351A0 *)(a1 + 0x80) = *(Q_3351A0 *)(a2 + 0x10);
        *(s32 *)(a3 + 0x430) = 0;
    }
    func_00457440(a2, a3 + 0x3F0);
    *(Q_3351A0 *)(a3 + 0x400) = *(Q_3351A0 *)(*(u8 **)(a3 + 0x440) + 0x10);
    if (a5[0x97] == 0) {
        a6->f24(a2, 0, 10);
    } else {
        a6->f20(a2, 0, 10);
    }
    return 0;
}
/* localdecomp:end func_003351A0 */
