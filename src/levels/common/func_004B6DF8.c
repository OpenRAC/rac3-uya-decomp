#include "common.h"

typedef struct {
    u8 active;
    u8 pad[0xEF];
} Ent4B6DF8;

extern u8 D_001425C0[];
extern Ent4B6DF8 D_002C5640[];
extern void func_00416BF8(s32);

void func_004B6DF8(void) {
    s32 i;
    for (i = 0; i < 156; i++) {
        u8 *p = &D_001425C0[i];
        if (i != 9 && D_002C5640[*p].active) {
            func_00416BF8(i);
        }
    }
}
