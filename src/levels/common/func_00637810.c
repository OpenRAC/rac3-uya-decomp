#include "common.h"

typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    s32 wDC;
} S_637810_Ent;

typedef struct {
    u8 pad0[0x80];
} S_637810_Slot;

typedef struct {
    u8 pad0[0x2400];
    s32 handles[9];
    s32 keys[9];
} S_637810;

extern S_637810_Slot D_001FE1A0[];
extern s32 func_005F0CE0(s32, s32, s32);

void func_00637810(S_637810 *self, s32 i, s32 key, s32 arg) {
    s32 h = self->handles[i];
    if (h != -1) {
        S_637810_Ent *e = (S_637810_Ent *)&D_001FE1A0[h];
        if (e->wDC == key && e->bD0 != 0) {
            goto done;
        }
    }
    self->handles[i] = func_005F0CE0(arg, 4, key);
done:
    self->keys[i] = key;
}
