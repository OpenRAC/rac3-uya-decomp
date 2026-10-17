#include "common.h"

typedef struct {
    s32 idx;
    u8 pad[0x40];
} S_482AE0;

extern S_482AE0 D_002EA318[];
extern u8 D_00142CA0[];
extern s32 func_004821B0(s32, s32, s32);
extern void func_00512AB0(s32, s32, s32);

void func_00482AE0(void) {
    s32 i;
    for (i = 0; i < 20; i++) {
        s32 h = func_004821B0(i, 0xE002D, 0xE0038);
        if (D_00142CA0[D_002EA318[i].idx]) {
            func_00512AB0(h, 1, 1);
        } else {
            func_00512AB0(h, 1, 0);
        }
    }
}
