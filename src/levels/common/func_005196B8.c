#include "common.h"

/* localdecomp:start func_005196B8 */
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 func_005196B8(S_3E7EC8 *a, s32 b);

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E8838;
typedef struct { s32 *e[16]; s32 pad[2]; s32 n; } O_003E8838;
typedef struct { u8 p0[0x2C]; O_003E8838 *x2C; } T_003E8838;
extern S_003E8838 D_001E1660_003E8838[];
extern s32 *func_00511BF8();
extern s32 func_00511E28();
extern s32 func_00511368();
extern s32 D_001DC160;
extern s32 func_005121D8();
extern void func_005121C8();
s32 func_005196B8(S_3E7EC8 *a, s32 key) {
    T_003E8838 *self = (T_003E8838 *)a;
    S_003E8838 *q;
    S_003E8838 *p;
    void *t;
    s32 v;
    s32 i, cnt;
    s32 *slot;
    p = D_001E1660_003E8838;
    if (p->x4) q = p;
    else q = (S_003E8838 *)func_00511BF8(p);
    t = (void *)func_00511368(func_00511E28(q), key);
    if (t == 0 || (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001DC160) == 0) t = 0;
    v = (s32)t;
    if (v == 0) return 0;
    cnt = 0;
    for (i = 0; i < self->x2C->n; i++) {
        if (*(s32 *)((i << 2) + (s32)self->x2C) == v) cnt++;
    }
    if (cnt != 0) return 0;
    if (self->x2C->n < 16) {
        slot = (s32 *)((self->x2C->n << 2) + (s32)self->x2C);
        if (*slot != 0) func_005121D8(*slot);
        *slot = v;
        if (v != 0) func_005121C8(v);
        self->x2C->n = self->x2C->n + 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_005196B8 */
