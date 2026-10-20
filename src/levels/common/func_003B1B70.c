#include "common.h"

typedef struct {
    u8 pad[12];
    s32 id;
} Vars_003B1B70;

extern u16 *D_0021DEA0[];
extern s32 D_001E00D8;
extern u8 *D_001E009C;
extern void func_003B4C58(u8 *);

void func_003B1B70(u8 *obj) {
    Vars_003B1B70 *v = *(Vars_003B1B70 **)(obj + 104);
    u16 *p;
    u8 *e;

    if (v->id == -1) {
        return;
    }
    p = D_0021DEA0[v->id];
    while ((v->id & 0xFF) != 255 && v->id <= D_001E00D8 && p != 0
           && ((s16)p[-1] >= 0 || p == D_0021DEA0[v->id])) {
        e = D_001E009C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        func_003B4C58(e);
        p++;
    }
}
