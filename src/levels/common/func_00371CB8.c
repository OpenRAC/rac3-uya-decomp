#include "common.h"

/* localdecomp:start func_00371CB8 */
typedef struct {
    u8 b[8];
} Pair_371CB8;

typedef struct {
    u8 pad0[16];
    f32 pos[4];
    u8 pad32[4];
    s32 i36;
    s32 i40;
    u8 pad44[4];
    f32 f48;
} Obj_371CB8;

extern Pair_371CB8 D_001DDA10[];
extern void func_004C41E8(void *a, void *b);
extern f32 func_0040BEF8(void *a, void *b);
extern void func_004C3500(f32 s, void *a, void *b, void *c, s32 d);
extern void func_00437698(void *a, s32 b, void *c);
extern f32 func_0040CEC8(f32 a, f32 b);
extern s32 func_004C7670(void);
extern void func_004C6EC8(void *a, void *b);
extern void func_004082B0(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern f32 func_00440978(void);

void func_00371CB8(u8 *moby) {
    u8 buf[16];
    Pair_371CB8 tmp;
    f32 vec[4];
    Obj_371CB8 *o = *(Obj_371CB8 **)(moby + 104);

    func_004C41E8(o, buf);
    if (func_0040BEF8(o->pos, buf) <= 0.9f) {
        o->i40 = 0;
    } else {
        o->i40 = 1;
    }
    tmp = D_001DDA10[0];
    if (o->i36) {
        if (o->i40) {
            func_004C3500(1.0f, o, o->pos, 0, 1);
        } else {
            func_004C3500(1.0f, o, o->pos, &tmp, 1);
        }
    }
    func_00437698(moby, 1, vec);
    o->f48 = func_0040CEC8(o->f48, 0.017453292f);
    if (func_004C7670()) {
        func_004C6EC8(vec, vec);
    }
    func_004082B0(vec, 57, 0x50505050, 1, 0.25f, 0.0f, func_0040CEC8(o->f48 * 2.5f, 0.0f));
    func_004082B0(vec, 42, 0x307F2040, 1, 0.25f, 0.0f, func_0040CEC8(-o->f48 * 1.5f, 0.0f));
    func_004082B0(vec, 44, 0x307F2040, 1, 0.25f, 0.0f, func_0040CEC8(o->f48, 0.0f));
    func_004082B0(vec, 49, 0x30FF7F00, 1, 0.18f, 0.0f, o->f48 * 0.5f);
    func_004082B0(vec, 49, 0x0030FF7F, 1, 0.18f, 0.0f, o->f48 * -0.5f);
    func_004082B0(vec, 47, 0x607F7F7F, 1, 0.06f, 0.0f, func_00440978());
}
/* localdecomp:end func_00371CB8 */
