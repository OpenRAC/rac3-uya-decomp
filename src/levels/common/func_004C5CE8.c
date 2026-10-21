#include "common.h"

/* localdecomp:start func_004C5CE8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    u8 pad20[4];
    u8 *p24;
    u8 pad28[8];
    u8 b30;
    u8 b31;
    s16 h32;
    u16 flags;
    u8 pad36[0xBA];
    u128_t qF0;
} Obj_004C5CE8;
extern Obj_004C5CE8 *D_001E11B8[];
extern void func_004C5C88(Obj_004C5CE8 *, s32);
extern void func_00441BA0(Obj_004C5CE8 *, s32, s32);
extern void func_00439610(Obj_004C5CE8 *);
Obj_004C5CE8 *func_004C5CE8(s32 a, s32 b, Obj_004C5CE8 *c) {
    Obj_004C5CE8 *p = D_001E11B8[0];
    if (c != 0) {
        p = c;
    }
    func_004C5C88(p, a);
    p->flags &= 0xFFBC;
    __asm__("sq $0,%0" : "=m"(p->qF0));
    p->b30 = 0xFF;
    p->h32 = 0x20;
    p->b31 = 1;
    p->f10 = 5.0f;
    p->f14 = 5.0f;
    p->f18 = 900.0f;
    p->f1C = 1.0f;
    if (b >= 0) {
        func_00441BA0(p, b, 0);
    } else if (p->p24 != 0 && p->p24[0xC] >= 2) {
        func_00441BA0(p, 1, 0);
    }
    if ((p->flags & 4) == 0) {
        func_00439610(p);
    }
    return p;
}
/* localdecomp:end func_004C5CE8 */
