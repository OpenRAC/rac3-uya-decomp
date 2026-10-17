#include "common.h"

typedef struct {
    f32 unk0;
    s16 unk4;
    char pad6[0x10 - 0x6];
    f32 unk10;
    char pad14[0x50 - 0x14];
    char unk50[0x70 - 0x50];
    s32 unk70;
    char pad74[0x80 - 0x74];
    s32 unk80;
    char pad84[0x90 - 0x84];
    f32 unk90;
    f32 unk94;
    f32 unk98;
} Vars;

typedef struct {
    char pad0[0x24];
    f32 unk24;
} Class;

typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x2C - 0x28];
    f32 scale;
    char pad30[0x68 - 0x30];
    Vars *vars;
} Moby;

extern f32 D_001DD1B0;
extern f32 D_001DD1D0;
extern f32 D_001DD1D4;
extern void func_00345E88(Moby *, void *);

void func_00349D88(Moby *m) {
    Vars *v = m->vars;

    if (v->unk10 <= 0.0f) {
        v->unk10 = D_001DD1B0 * m->scale / m->cls->unk24;
    }
    v->unk0 = v->unk4;
    func_00345E88(m, v->unk50);
    v->unk70 = 1;
    if (v->unk90 <= 0.0f) {
        v->unk90 = D_001DD1D0;
    }
    if (v->unk94 <= 0.0f) {
        v->unk94 = D_001DD1D4;
    }
    v->unk98 = 0.0f;
    v->unk80 = 0;
}
