#include "common.h"

/* localdecomp:start func_00321C00 */
typedef struct {
    u8 pad[0x20];
    u8 t;
    u8 pad2[0x10];
    u8 c;
    u8 pad3[2];
    u16 fl;
} Obj_00321C00;
extern Obj_00321C00 *D_001E1838[7];
Obj_00321C00 *func_00321C00(void) {
    s32 i;
    Obj_00321C00 *o;
    for (i = 0; i < 7; i++) {
        o = D_001E1838[i];
        if (o != 0) {
            D_001E1838[i] = 0;
            if (o->t == 0xFE) goto z;
            if (o->t == 0xFD) goto z;
            if (o->fl & 2) goto z;
            if (o->c != 0) goto r;
z:
            return 0;
r:
            return o;
        }
    }
    return 0;
}
/* localdecomp:end func_00321C00 */
