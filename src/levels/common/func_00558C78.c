#include "common.h"
typedef struct { s32 w0; u8 p0[0x74]; s32 w78; u8 p1[0xC4]; s32 w140; } V_558C78;
typedef struct { u8 p0[0x68]; V_558C78 *v; } M_558C78;
extern void func_00558B10(M_558C78 *);
void func_00558C78(M_558C78 *m) {
    V_558C78 *v = m->v;
    s32 s;
    if (v->w78 != 0) {
        s = v->w0;
        if (s == 5 || v->w140 == 1) {
            if (s != 0) {
                func_00558B10(m);
            }
        }
    }
}
