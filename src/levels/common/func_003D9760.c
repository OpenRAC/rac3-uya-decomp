#include "common.h"

typedef struct { u8 p0[0x31]; u8 b31; u8 p32[0x36]; void *w68; } M_3D9760;
extern s32 func_00405140(void *);
extern void func_003D95D0(M_3D9760 *);

void func_003D9760(M_3D9760 *m) {
    if (func_00405140(m->w68) && m->b31) {
        func_003D95D0(m);
    }
}
