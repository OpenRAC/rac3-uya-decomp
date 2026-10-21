#include "common.h"

/* localdecomp:start func_0051B950 */
extern s32 func_00519410();
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 func_00519410(void *, s32);
extern f32 D_001DC128;
extern f32 D_001DC12C;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3E89F0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
typedef struct O_3E8EC8 O_3E8EC8F;
typedef struct { u8 p0[0x20]; void (*f20)(O_3E8EC8F *, s32, f32 *, s32); } V_3E8EC8;
typedef struct O_3E8EC8 { u8 p0[8]; V_3E8EC8 *f8; u8 pC[0x20]; struct { s32 *e[1]; u8 pad[0x44]; s32 n; } *f2C; } O_3E8EC8;
extern void func_00519608();
typedef struct S_003E9C50_obj S_003E9C50_obj;
typedef struct {
    u8 pad0[8];
    void (*f8)(S_003E9C50_obj *, s32);
    void (*fC)(S_003E9C50_obj *);
} S_003E9C50_vt;
struct S_003E9C50_obj { s32 f0; S_003E9C50_vt *vt; };

typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C, f20, f24; u32 f28; u8 pad2[0xC]; s32 f38; s32 f3C; u32 f40; u32 f44; u8 pad3[0x4]; u32 f4C; u32 f50; u8 pad4[0x8]; f32 f5C; f32 f60;
} O_3EAAD0;
extern f32 D_001DC128;
extern f32 D_001DC12C;
extern f32 D_001DC144;
extern s32 func_00519410();
extern void func_00519608();
extern void func_0040DBE0_003EAAD0(unsigned long, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
void func_0051B950(O_3EAAD0 *o, s32 a) {
    f32 b[4];
    s32 flag, r;
    f32 x, y, z;
    f32 cx, cy, h, dy, w;
    unsigned long p50, p28;
    s32 p3C;
    if (o->f3C == 0) return;
    flag = 0;
    x = 0.0f;
    z = x;
    ((void (*)())o->vt[8])(o, a, b, 1);
    func_00519608(o, b);
    y = x;
    cx = b[0] + (b[2] - b[0]) * 0.5f;
    cy = b[1] + (b[3] - b[1]) * 0.5f;
    r = func_00519410(o, 0x40);
    if (r) {
        x = o->f20;
        y = o->f24;
        flag = 1;
    }
    h = o->f60;
    dy = D_001DC144 * h;
    p28 = o->f28;
    p3C = o->f3C;
    w = o->f5C;
    p50 = o->f50;
    if (flag) {
        func_0040DBE0_003EAAD0(p50, p3C, -1, 1, flag, p28, (f32)(s32)(cx * D_001DC128), (f32)(s32)((cy - dy) * D_001DC12C), w, h, x * D_001DC128, y * D_001DC12C);
    } else {
        func_0040DBE0_003EAAD0(p50, p3C, -1, 1, 0, p28, (f32)(s32)(cx * D_001DC128), (f32)(s32)((cy - dy) * D_001DC12C), w, h, z, z);
    }
}
/* localdecomp:end func_0051B950 */
