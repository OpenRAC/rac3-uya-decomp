#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x2];
    s16 active;
    char pad14[0x18 - 0x14];
    f32 unk18;
    f32 unk1C;
    char pad20[0x40 - 0x20];
} Entry;

typedef struct {
    char pad0[0x1A];
    s16 unk1A;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
} Moby;

typedef struct {
    s32 unk0;
    s32 offset;
} Info;

extern char *func_00454190(s32, s32);
extern Info *func_004541C0(s32, s32);
extern s32 func_0040BAC0(void *);
extern f32 func_0040CEC8(f32, f32);

s32 func_00348B90(Moby *m) {
    Vars *v = m->vars;
    Entry *e;
    s32 i;
    s32 count = 0;

    e = (Entry *)(func_00454190(3076, v->unk1A) + func_004541C0(3076, v->unk1A)->offset);
    for (i = 0; i < 120; i++) {
        if (e[i].active != 0) {
            if (func_0040BAC0(e[i].pos) != 0) {
                e[i].active = 0;
            } else {
                count++;
                e[i].unk18 = func_0040CEC8(e[i].unk18, e[i].unk1C);
            }
        }
    }
    return count;
}
