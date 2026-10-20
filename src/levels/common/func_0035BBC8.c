#include "common.h"

typedef struct {
    u8 pad[0x10];
    f32 f10;
    u8 pad2[0x24 - 0x14];
    int x24;
    f32 f28;
} S_35BBC8v;
typedef struct {
    u8 pad[0x68];
    S_35BBC8v *v;
} S_35BBC8;

extern f32 func_0040CEC8(f32, f32);
extern void func_004082B0(void *, int, int, int, f32, f32, f32);
extern f32 func_00440978(void);
extern f32 func_0040BF38(S_35BBC8v *);
extern void func_0035B9E8(S_35BBC8 *);

void func_0035BBC8(S_35BBC8 *o) {
    S_35BBC8v *v = o->v;
    void *pos;

    if (v == 0) {
        return;
    }
    pos = (u8 *)o + 16;
    v->f10 = func_0040CEC8(v->f10, 0.017453292f);
    func_004082B0(pos, 57, 0x207F7F7F, 1, 0.75f, 0.08f, func_0040CEC8(-v->f10 * 1.5f, 0.0f));
    func_004082B0(pos, 57, 0x207F7F7F, 1, 0.75f, 0.08f, v->f10 * 0.5f);
    func_004082B0(pos, 57, 0x207F7F7F, 1, 0.75f, 0.08f, func_0040CEC8(v->f10 * 2.5f, 0.0f));
    func_004082B0(pos, 49, 0x1000FFFF, 1, 0.5f, 0.08f, v->f10 * 0.5f);
    func_004082B0(pos, 49, 0x1000FFFF, 1, 0.5f, 0.08f, v->f10 * -0.5f);
    func_004082B0(pos, 47, 0x507F7F7F, 1, 0.2f, 0.08f, func_00440978());
    if (v->x24 != 0) {
        v->f28 += func_0040BF38(v);
        if (2.0f < v->f28) {
            func_0035B9E8(o);
        }
    }
}
