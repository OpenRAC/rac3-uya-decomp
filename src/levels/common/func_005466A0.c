#include "common.h"

typedef struct {
    char pad0[0x3];
    u8 flags;
} Ent;

extern Ent *func_0061B038(s32);

void func_005466A0(s32 id, f32 *a, f32 *b) {
    Ent *e = func_0061B038(id);
    Ent *r;

    r = 0;
    if (e != 0) {
        if (e->flags & 0xF) {
            r = 0;
        } else {
            r = e;
        }
    }

    if (r != 0) {
        if (a != 0) {
            *a = 4.0f;
        }
        if (b != 0) {
            *b = 7.0f;
        }
    } else {
        if (a != 0) {
            *a = 7.0f;
        }
        if (b != 0) {
            *b = 15.0f;
        }
    }
}
