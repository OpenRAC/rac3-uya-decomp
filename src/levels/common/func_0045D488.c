#include "common.h"
typedef struct {
    u8 pad[398];
    s16 x18E;
    s32 x190;
    u8 pad2[196];
    f32 x258[30];
} Struct001CD0C0;
extern Struct001CD0C0 D_001CD0C0;
f32 func_0045D488(s32 a0, Struct001CD0C0 *a1) {
    Struct001CD0C0 *p;
    if (a1 != 0) p = a1; else p = &D_001CD0C0;
    if (p->x190 < a0) a0 = p->x190;
    return p->x258[(p->x18E - a0 + 30) % 30];
}
