#include "common.h"

typedef struct M_3AC248 M_3AC248;
typedef struct { M_3AC248 *w0; s32 w4; } S_3AC248;
struct M_3AC248 { u8 p0[0x20]; u8 b20; u8 p21[0x47]; s32 *w68; u8 p6C[0x3E]; s16 hAA; };
typedef struct { u8 p0[0x68]; S_3AC248 *w68; } O_3AC248;

void func_003AC248(O_3AC248 *m) {
    S_3AC248 *s = m->w68;
    M_3AC248 *o = s->w0;
    if (o != 0 && o->hAA == 7169 && o->b20 != 254 && o->b20 != 253) {
        s32 *p = o->w68;
        s->w4 = 32;
        *p = 0;
    }
}
