#include "common.h"

typedef struct { u8 pad[0x2A0]; s32 f2A0; } V_424328;
typedef struct { u8 pad[0x20]; u8 state; u8 p21[0x47]; V_424328 *vars; } S_424328;
extern void func_0047F900(S_424328 *, s32, s32);

void func_00424328(S_424328 *m) {
    V_424328 *v = m->vars;
    if (v->f2A0 != 0) {
        v->f2A0 = 0;
        if (m->state == 1 || m->state == 4) {
            func_0047F900(m, 2, -1);
        }
    }
}
