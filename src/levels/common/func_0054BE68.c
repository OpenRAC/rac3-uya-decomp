#include "common.h"
typedef struct { u8 pad[108]; u8 b108; } Sub_0054BE68;
typedef struct { u8 pad0[32]; u8 b32; u8 pad1[71]; Sub_0054BE68 *sub; } Obj_0054BE68;
extern Obj_0054BE68 *D_003BDE20[][24];
s32 func_0054BE68(s32 a0, s32 a1, s32 a2, u8 *a3) {
    Obj_0054BE68 *o = D_003BDE20[a3[2]][a3[0]];
    if (o != 0 && o->b32 != 254 && o->b32 != 253) {
        Sub_0054BE68 *s = o->sub;
        if (s->b108 == 0) s->b108 = a3[1];
    }
    return 3;
}
