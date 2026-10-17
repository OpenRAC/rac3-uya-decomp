#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct Moby Moby;

typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;

typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;

struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};

extern s32 func_004EB788(s32);
extern void func_003F06E8(Moby *, s32);

void func_003F08B0(Moby *self) {
    Vars *v = self->pVar;
    s32 i;

    func_004EB788(v->field_304);
    for (i = 0; i < v->count; i++) {
        Vars *w = v->items[i]->pVar;
        func_003F06E8(v->items[i], w->field_304);
        ((u8 *)w)[829] = 1;
        w->field_304 = 0;
        w->field_29C = 0;
        w->field_300 = 1;
        ((u8 *)w)[828] = 0;
        v->items[i]->field_20 = 1;
        ((VarsB *)w)->pos = v->items[i]->pos;
        ((VarsB *)w)->field_354 = 0;
    }
}
