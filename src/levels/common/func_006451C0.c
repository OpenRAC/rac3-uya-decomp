#include "common.h"

typedef struct {
    s32 ids[8];
} IdList;

extern IdList D_00246210;
extern s32 func_0066F8B8(s32);

s32 func_006451C0(void) {
    IdList list = D_00246210;
    s32 *p = list.ids;
    s32 i;
    s32 ret = 10;

    for (i = 0; i < 8; i++) {
        if (func_0066F8B8(*p) != 0) {
            ret = *p;
            break;
        }
        p++;
    }
    return ret;
}
