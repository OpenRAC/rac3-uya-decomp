#include "common.h"

typedef struct {
    u8 pad0[202];
    s16 idx;
    u8 pad1[4];
    u8 active;
    u8 pad2[11];
    s32 id;
    u8 pad3[52];
} Slot;

typedef struct {
    u8 pad[10124];
    s32 slot[9];
    s32 id[9];
} SlotMap;

extern SlotMap D_001A4BE0;
extern u8 D_001A30B0[];
extern s32 func_004A7200(s32, s32, s32);

void func_004F1110(s32 i, s32 id, s32 x) {
    s32 s;
    Slot *e;

    s = D_001A4BE0.slot[i];
    if (s != -1) {
        e = (Slot *)(D_001A30B0 + s * 128);
        if (e->id == id && e->active != 0) {
            goto done;
        }
    }
    D_001A4BE0.slot[i] = func_004A7200(x, 4, id);
done:
    D_001A4BE0.id[i] = id;
}
