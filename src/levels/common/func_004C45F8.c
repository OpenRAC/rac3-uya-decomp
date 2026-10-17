#include "common.h"

typedef struct {
    u8 pad[64];
    s32 handle;
    u8 pad2[12];
} Ent_004C45F8;

extern Ent_004C45F8 D_0024E660[];
extern void func_004373D8(s32, Ent_004C45F8 *);

void func_004C45F8(u32 i) {
    Ent_004C45F8 *e;

    if (i < 64) {
        e = &D_0024E660[i];
        func_004373D8(e->handle, e);
        e->handle = 0;
    }
}
