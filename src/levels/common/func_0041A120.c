#include "common.h"
typedef struct {
    u8 pad[16];
    void (*fn)(void *);
    u8 pad2[124];
} Entry_41A120;
extern Entry_41A120 D_002E6110[];
s32 func_0041A120(s32 a0) {
    Entry_41A120 *p = &D_002E6110[a0 & 0xF];
    s32 r = 0;
    if (p != 0 && p->fn != 0) {
        p->fn(p);
        r = 1;
    }
    return r;
}
