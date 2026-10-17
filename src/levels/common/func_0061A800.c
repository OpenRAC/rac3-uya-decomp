#include "common.h"

typedef struct {
    u8 pad[300];
    s32 count;
    u8 pad2[24];
    s32 ids[1];
} Tbl_0061A800;

extern Tbl_0061A800 D_001A5E50;

s32 func_0061A800(s32 id) {
    s32 i;

    for (i = 0; i < D_001A5E50.count; i++) {
        if (D_001A5E50.ids[i] == id) {
            return 1;
        }
    }
    return 0;
}
