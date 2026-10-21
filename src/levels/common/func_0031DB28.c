#include "common.h"

/* localdecomp:start func_0031DB28 */
typedef struct {
    u8 pad0[0x24];
    u8 *x24;
    u8 pad28[0xC];
    u16 h34;
} T_31DB28;
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[0x14];
} H_31DB28;
typedef struct {
    u8 pad0[0x6C];
    f32 f6C;
    u8 pad70[0x80];
} G_31DB28;
typedef struct {
    u8 pad0[0x18];
    T_31DB28 *x18;
} D_31DB28;

extern D_31DB28 D_001EAA80[];
extern T_31DB28 *D_001A71A0[];
extern u8 D_0014263F[];
extern G_31DB28 D_002C5640[];
extern s32 func_003F8448(void *, void *, s32, u8 *, s32);
extern void func_0040C0F0(f32 *, s32, f32);
extern void func_00443628(H_31DB28 *, u8 *, s32, f32 *, f32);
extern void func_00443840(T_31DB28 *, H_31DB28 *);
extern void func_0031DF08(u8 *, s32, s32, u8 *);

void func_0031DB28(u8 *obj, void *a1) {
    f32 v[4];
    H_31DB28 h;
    s32 m = *(s32 *)(obj + 104);
    T_31DB28 *t;

    if (func_003F8448(a1, obj + 16, 0, obj, 0) == 0) {
        return;
    }
    t = D_001EAA80[0].x18;
    if (t != 0) {
        if (t != D_001A71A0[0] && (t->x24[70] == 5 || (t->h34 & 0x4000))) {
            func_0040C0F0(v, m, 1.0f);
            func_00443628(&h, obj, 0x410000, v, (D_002C5640 + D_0014263F[0])->f6C * 0.1f);
            h.b18 = 5;
            h.b19 = 3;
            h.h1A = *(u16 *)(obj + 170);
            func_00443840(D_001EAA80[0].x18, &h);
            func_0031DF08(obj + 16, 10, 1, obj);
        }
        if (D_001EAA80[0].x18 != 0) {
            obj[32] = 2;
            return;
        }
    }
    func_0031DF08(obj + 16, 15, 0, obj);
    obj[32] = 2;
}
/* localdecomp:end func_0031DB28 */
