#include "common.h"

extern void func_00511B18(void *);
typedef struct O { struct VT *vt; u8 pad[0x18]; } O;
struct VT { u8 pad[0x10]; void (*fn)(O *, s32); };
typedef struct { u8 pad[0x64]; void (*fn[4])(void); s32 count; } Q_3E1548;

typedef struct { u8 pad[0x50]; void (*fn[4])(void); s32 count; } Q_3E15D8;
typedef struct { s32 pad; Q_3E15D8 *q; } S_3E15D8;
void func_00511B18(void *arg0) {
    S_3E15D8 *p = (S_3E15D8 *)arg0;
    s32 i;
    for (i = 0; i < p->q->count; i++) {
        if (p->q->fn[i]) {
            p->q->fn[i]();
            p->q->fn[i] = 0;
        }
    }
    p->q->count = 0;
}
