#include "common.h"

typedef struct { u8 p0[0x2C]; s32 w2C; u8 p30[0x20]; s32 w50; s32 w54; } S_3AC2C8;
typedef struct { u8 p0[0x68]; S_3AC2C8 *w68; } M_3AC2C8;
extern void func_003ACF48(M_3AC2C8 *);
extern void func_003ACED8(M_3AC2C8 *);
extern void func_003AC248(M_3AC2C8 *);

void func_003AC2C8(M_3AC2C8 *m) {
    S_3AC2C8 *s = m->w68;
    s->w54 = 0;
    s->w50 = 0;
    s->w2C = 0;
    func_003ACF48(m);
    func_003ACED8(m);
    func_003AC248(m);
}
