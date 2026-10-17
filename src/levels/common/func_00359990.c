#include "common.h"
typedef struct { u8 pad[0x68]; u8 *x68; } O_359990;
extern s32 func_00354E20(O_359990 *, u8 *);
extern s32 func_00354BA0(O_359990 *, u8 *);
s32 func_00359990(O_359990 *o) {
    s32 r = 0;
    u8 *p = o->x68 + 0x220;
    if (func_00354E20(o, p) == 0) {
        r = func_00354BA0(o, p) != 0;
    }
    return r;
}
