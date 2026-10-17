#include "common.h"

typedef struct {
    u8 pad0[12];
    s16 unkC;
    u8 padE[33 - 14];
    s8 unk21;
    u8 pad22[128 - 34];
} Elem_006365A8;

extern Elem_006365A8 D_0049C950[];
extern void func_0061FAE8(u8 *);
extern s32 func_00646268(u8 *, s32);
extern void func_005B7850(u8 *, f32);
extern void func_00628CD0(u8 *, s32, s32, s32, f32);

s32 func_006365A8(u8 *p)
{
    s32 id;
    Elem_006365A8 *e;
    s32 (*fn)(u8 *, s32, s32, s32, s32);

    if (p[6663] == 0) {
        return 0;
    }
    if (p[6661] == 0) {
        return 0;
    }
    if (p[6664] != 0) {
        return 0;
    }
    id = -1;
    if (*(s32 *)(p + 1140) == 2) {
        id = *(s32 *)(p + 1144);
    }
    if (id != *(s32 *)(p + 9292)) {
        func_0061FAE8(p);
        return 0;
    }
    if (*(s32 *)(p + 1020) < 5) {
        return 0;
    }
    if (func_00646268(p, id)) {
        Elem_006365A8 *base = D_0049C950;
        e = &base[base[id].unk21];
    } else {
        e = &D_0049C950[id];
    }
    id = e->unkC;
    fn = (s32 (*)(u8 *, s32, s32, s32, s32))(*(void ***)(p + 20))[13];
    if (fn(p, 0, 0, 0, 1) != 0) {
        func_005B7850(p + 400, 0.0250000022f);
        if (0.0250000022f < *(f32 *)(p + 4020)) {
            *(f32 *)(p + 4020) = 0.0250000022f;
        }
        func_00628CD0(p, id, 0, 0, 11.0f);
        if (*(s32 *)(p + 1864) != 0) {
            *(s32 *)(p + 1876) = 1;
        }
        *(s32 *)(p + 9288) = id;
        return 1;
    }
    return 0;
}
