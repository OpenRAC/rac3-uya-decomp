#include "common.h"

typedef struct {
    s32 id;
    s32 pad;
} S_0054A238;
typedef struct {
    u8 pad[0x128];
    s32 time;
} G_0054A238;
extern G_0054A238 D_001A5E50;
extern S_0054A238 D_001DF8B8[8];
extern S_0054A238 D_0024B14C[8];

void func_0054A238(s32 id) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_001DF8B8[i].id == id) {
            if (D_001A5E50.time - 2000 < D_0024B14C[i].id) {
                D_001DF8B8[i].id = -1;
                return;
            }
        }
    }
}
