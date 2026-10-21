#include "common.h"

/* localdecomp:start func_0051D658 */
extern s32 func_00519410();
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 func_00519410(void *, s32);
extern void func_00519608();
extern void func_00519608(void *, f32 *);

typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C; u8 pad20[0x18]; s32 f38; f32 f3C; s32 f40; s32 f44;
} O_3EC7D8;
extern f32 D_001DC118[], D_001DC11C[], D_001DC120_003EC7D8[], D_001DC124_003EC7D8[], D_001DC128_003EC7D8[], D_001DC12C_003EC7D8[];
extern s32 func_00519410();
extern void func_00519608();
extern s32 func_004C9A70();
extern void func_004C7F48(void *, s32, f32, f32, f32, f32, f32);
void func_0051D658(O_3EC7D8 *o, s32 a) {
    f32 b[4];
    s32 p;
    f32 x, y;
    if (o->f44 == 0) return;
    o->vt[8](o, a, b, 1);
    if (func_00519410(o, 0x100) != 0) {
        f32 x, y;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        s32 k = o->f40;
        p = func_004C9A70(o->f44, k);
        x = o->f10; y = o->f14; fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_004C7F48((void *)p, fl, (x + D_001DC120_003EC7D8[0]) * D_001DC128_003EC7D8[0], (y + D_001DC124_003EC7D8[0]) * D_001DC12C_003EC7D8[0], c * D_001DC118[0], d * D_001DC11C[0], e);
    } else {
        s32 k;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        func_00519608(o, b);
        x = b[0] + (b[2] - b[0]) * 0.5f;
        y = b[1] + (b[3] - b[1]) * 0.5f;
        k = o->f40;
        p = func_004C9A70(o->f44, k);
        fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_004C7F48((void *)p, fl, (x + D_001DC120_003EC7D8[0]) * D_001DC128_003EC7D8[0], (y + D_001DC124_003EC7D8[0]) * D_001DC12C_003EC7D8[0], c * D_001DC118[0], d * D_001DC11C[0], e);
    }
}
/* localdecomp:end func_0051D658 */
