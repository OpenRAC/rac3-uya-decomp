#include "common.h"

typedef struct Ent144 {
    s32 a;
    void (*fn)(struct Ent144 *);
    u8 pad[136];
} Ent144;

typedef struct {
    u8 used;
    u8 pad[95];
} Ent96;

typedef struct {
    u8 pad[184];
    s32 count;
    Ent144 *ents;
} Mgr;

extern Mgr D_001A30B0;
extern Ent96 D_0023A870[12];
extern void func_004A79F8(Ent96 *);

void func_004A76F0(void) {
    s32 i;

    for (i = 0; i < D_001A30B0.count; i++) {
        if (D_001A30B0.ents[i].fn != 0) {
            D_001A30B0.ents[i].fn(&D_001A30B0.ents[i]);
        }
    }
    for (i = 0; i < 12; i++) {
        if (D_0023A870[i].used != 0) {
            func_004A79F8(&D_0023A870[i]);
        }
    }
}
