#include "common.h"
typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
extern N_65FDA0 *D_001DAAE4;
N_65FDA0 *func_0065FDA0(s32 *key, u32 type, s32 flag) {
    N_65FDA0 *p;
    s32 k = *key;
    for (p = D_001DAAE4; p != 0; p = p->next) {
        if (p->w8 == k && (p->w0 & 0xF) == type) {
            if (flag == 0 || p->b55 != 0) {
                break;
            }
        }
    }
    return p;
}
