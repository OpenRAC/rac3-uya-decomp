#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_2FCD98;
typedef struct { f32 x, y, z; } T_2FCD98;
typedef struct {
    u8 pad0[0x1210];
    u32 f1210;
    u8 pad1214[0x1220 - 0x1214];
    s32 f1220;
    u8 pad1224[0x25C4 - 0x1224];
    s32 f25C4;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 b25ED;
    u8 pad25EE[0x28BC - 0x25EE];
    s32 f28BC;
} G_2FCD98;
typedef struct {
    u8 pad0[0x1A0];
    u32 f1A0;
    u32 f1A4;
} P_2FCD98;
typedef struct {
    u8 pad0[16];
    V_2FCD98 v10;
    s32 f20;
    s32 f24;
} S_2FCD98;
typedef struct {
    u8 pad0[16];
    V_2FCD98 pos;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_2FCD98 *p68;
} O_2FCD98;
typedef struct {
    u8 pad0[0xB8];
    void *fB8;
} R_2FCD98;
extern u8 D_001A52D0[];
extern G_2FCD98 D_001A4BE0;
extern P_2FCD98 *D_001D52FC;
extern T_2FCD98 D_001DC460;
extern void func_00437698(void *, s32, void *);
extern s32 func_0044CF68(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32, s32, T_2FCD98, s32, s32, s32);
extern void func_004C3888(void *, void *, s32, f32, f32, f32, f32, s32);
extern s32 func_004C3E68(void *, void *, void *, void *, void *, s32, s32, f32);
extern s32 func_0040BA90(s32 *);
extern s32 func_0050D8F8(s32, s32);
extern void func_004E6A08(s32);
extern void func_004A7200(s32, s32, void *);
extern R_2FCD98 *func_002F9920(void *, void *);
extern void func_004E6CB0(void);
extern void func_004026A0(void *, void *);
extern void func_002FD068(void);

/* localdecomp:start func_002FCD98 */
void func_002FCD98(O_2FCD98 *obj) {
    V_2FCD98 a;
    T_2FCD98 t;
    V_2FCD98 b;
    V_2FCD98 c;
    S_2FCD98 *s;
    V_2FCD98 *pb;
    s32 r;
    s32 ok;
    f32 k;
    f32 d;

    s = obj->p68;
    func_00437698(obj, 0, &a);
    t = D_001DC460;
    r = func_0044CF68(&obj->pos, D_001A52D0, &c, 0, 0, 0,
                      0.39269909f, 0.7853982f, 11.1f, 0.0f, 0.0f, 0, t, 1, -1, 0);
    pb = &b;
    k = 10.0f;
    if (((G_2FCD98 *)(D_001A52D0 - 1776))->f25C4 == 29) {
        k = 11.0f;
    }
    d = 0.0030555557f;
    ok = 1;
    func_004C3888(pb, &a, r, 1.5f, k, 0.16666667f, d, 0);
    s->f24 = func_004C3E68(&a, pb, s, &s->v10, obj, 0, 0, d);
    if (((G_2FCD98 *)(D_001A52D0 - 1776))->f25C4 == 29) {
        if (!func_0040BA90(&((G_2FCD98 *)(D_001A52D0 - 1776))->f28BC)) {
            ok = 0;
        }
    } else {
        ((G_2FCD98 *)(D_001A52D0 - 1776))->f28BC = 40;
    }
    switch (obj->b20) {
    case 0:
        obj->b20 = 1;
        s->f24 = 0;
    case 1:
        if ((D_001D52FC->f1A0 & D_001A4BE0.f1210) && !D_001A4BE0.b25ED && D_001A4BE0.f1220 >= 23 && ok) {
            if (func_0050D8F8(-1, 1)) {
                func_004E6A08(-1);
                obj->b20 = 2;
                s->f20 = 20;
            } else if (D_001D52FC->f1A4 & D_001A4BE0.f1210) {
                func_004A7200(2, 0, obj);
            }
        }
        break;
    case 2:
        if (func_0040BA90(&s->f20)) {
            func_002F9920(&a, pb)->fB8 = obj;
            func_004E6CB0();
            obj->b20 = 3;
            s->f20 = 10;
        }
        break;
    case 3:
        if (func_0040BA90(&s->f20)) {
            obj->b20 = 1;
        }
        break;
    }
    func_004026A0(func_002FD068, obj);
}
/* localdecomp:end func_002FCD98 */
