#include "common.h"

/* localdecomp:start func_003D8420 */
typedef int Q_3D8420 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D8420;
struct O_3D8420;
typedef struct {
    u8 pad0[36];
    struct M_3D8420 *p24;
} N_3D8420;
typedef struct M_3D8420 {
    u8 pad0[70];
    u8 b46;
} M_3D8420;
typedef struct T_3D8420 {
    u8 pad0[16];
    V4_3D8420 v10;
    u8 b20;
    u8 pad21[3];
    M_3D8420 *p24;
    u8 pad28[12];
    u16 h34;
    u8 pad36[170];
    V4_3D8420 vE0;
} T_3D8420;
typedef struct {
    u8 pad0[8];
    f32 f08;
    f32 f0C;
    u8 pad10[24];
    T_3D8420 *p28;
    u8 pad2C[4];
    s32 i30;
    f32 f34;
    u8 pad38[4];
    s32 i3C;
    u8 pad40[12];
    u8 a4C[4];
} P_3D8420;
typedef struct O_3D8420 {
    u8 pad0[16];
    V4_3D8420 v10;
    u8 b20;
    u8 pad21[34];
    u8 b43;
    u8 pad44[36];
    P_3D8420 *p68;
} O_3D8420;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s32 iC;
    f32 x, y, z, w;
} E_3D8420;
typedef struct {
    u8 pad0[16];
    f32 f10;
} R_3D8420;
extern E_3D8420 D_001F1BC0[];
extern void func_00444070(O_3D8420 *, f32);
extern void func_0040BA90(void *);
extern s32 func_00421DE0(void *, f32, s32, f32);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern s32 func_0040D020(s32, s32, f32);
extern T_3D8420 *func_0044CD90(void *, f32, f32, f32, f32, s32);
extern R_3D8420 *func_00440728(T_3D8420 *);
extern void func_0040BE90(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, O_3D8420 *, s32);
extern void func_00441FB8(O_3D8420 *, s32, s32);
extern void func_00441C78(O_3D8420 *, s32, s32, s32);
extern void func_003D8B38(O_3D8420 *);
extern void func_003D9008(O_3D8420 *);
s32 func_003D8420(O_3D8420 *obj) {
    P_3D8420 *p = obj->p68;
    V4_3D8420 *pos;
    V4_3D8420 v;
    V4_3D8420 tmp;
    T_3D8420 *t;
    R_3D8420 *q;
    s32 c;
    f32 s;

    if (p == 0) {
        return 1;
    }
    func_00444070(obj, 0.6f);
    pos = &obj->v10;
    func_0040BA90(p->a4C);
    if (p->i30 == -1) {
        p->i30 = func_00421DE0(pos, 5.5f, 0x4080FF, 0.0f);
    }
    v = obj->v10;
    if (p->i30 >= 0) {
        (D_001F1BC0 + p->i30)->x = v.x;
        (D_001F1BC0 + p->i30)->y = v.y;
        (D_001F1BC0 + p->i30)->z = v.z;
        p->f34 = func_0040CEC8(p->f34, func_004408C0(800.0f, 160.0f) * 0.017453292f * 0.016666668f);
        (D_001F1BC0 + p->i30)->w = func_0040C3E0(p->f34 * 0.1f) * 0.5f + 0.5f + 3.5f;
        c = func_0040D020(0x3065FF, 0x5585FF, func_0040C3E0(p->f34) * 0.5f + 0.5f);
        (D_001F1BC0 + p->i30)->f0 = (c & 0xFF) * 0.0078125f;
        (D_001F1BC0 + p->i30)->f4 = ((c >> 8) & 0xFF) * 0.0078125f;
        (D_001F1BC0 + p->i30)->f8 = ((c >> 16) & 0xFF) * 0.0078125f;
    }
    if ((u8)(obj->b20 - 2) >= 2 && obj->b20 != 0) {
        tmp = obj->v10;
        t = func_0044CD90(&tmp, 1.0471976f, 30.0f, -1.0f, -1.0f, 0);
        p->p28 = t;
        if (t != 0 && !(t->h34 & 2) && t->b20 != 254 && t->b20 != 253 && t->p24 != 0 && t->p24->b46 == 5) {
            tmp = t->v10;
            q = func_00440728(p->p28);
            if (q != 0) {
                func_0040BE90(&tmp, &p->p28->vE0, q->f10);
                __asm__ __volatile__(
                    "lqc2 $vf1, %0\n"
                    "lqc2 $vf2, %1\n"
                    "vadd.xyz $vf1, $vf1, $vf2\n"
                    "sqc2 $vf1, %0\n"
                    : "+m"(tmp) : "m"(p->p28->v10) : "memory");
            }
            if (func_003F8448(pos, &tmp, 2, obj, 0) != 0) {
                p->p28 = 0;
                func_00441FB8(obj, 3, -1);
                if (obj->b43 != 3) {
                    func_00441C78(obj, 3, 0, 0);
                }
            } else {
                func_00441FB8(obj, 2, -1);
                func_00441C78(obj, 5, 0, 10);
            }
        } else {
            p->p28 = 0;
        }
    }
    if (obj->b20 == 2) {
        p->f0C = func_0040CEC8(p->f0C, p->f08);
        s = func_0040C3E0(p->f0C);
        s *= func_004408C0(0.01f, 0.03f);
        obj->v10.z += s;
    } else {
        p->f0C = func_0040CEC8(p->f0C, p->f08);
        s = func_0040C3E0(p->f0C);
        s *= func_004408C0(0.0025f, 0.0075f);
        obj->v10.z += s;
    }
    func_003D8B38(obj);
    if (p->i3C >= 11) {
        func_003D9008(obj);
    }
    return 0;
}
/* localdecomp:end func_003D8420 */
