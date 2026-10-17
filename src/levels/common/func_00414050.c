#include "common.h"

typedef struct {
    s32 x0;
    u8 pad[0x2D];
    u8 x31;
} S_414050;

extern S_414050 *func_0053EAA0(s32);

void func_00414050(S_414050 **p, s32 *id) {
    if (*p != 0) {
        if ((*p)->x0 != *id) {
            *p = 0;
        }
        if (*p != 0 && (*p)->x31 == 0) {
            *p = 0;
            *id = 0;
        }
    }
    if (*p == 0 && *id != 0) {
        *p = func_0053EAA0(*id);
    }
}
