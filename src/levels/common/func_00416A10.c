#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[0xF0 - 0xC];
} S_416A10;

extern s32 func_00416968(s32);
extern u8 D_001425C0[];
extern S_416A10 D_002C5640[];
extern s32 D_001D4C60;
extern s32 D_001D4C80;

void func_00416A10(s32 id) {
    s32 i;

    if (func_00416968(id) == 0) {
        return;
    }
    if ((D_002C5640 + D_001425C0[id])->w8 != 0 && id != 30) {
        return;
    }
    for (i = 0; i < 8 && (&D_001D4C60)[i] != 0; i++) {
        if ((&D_001D4C60)[i] == id || (&D_001D4C80)[i] == id) {
            return;
        }
    }
    if (i < 8) {
        (&D_001D4C60)[i] = id;
        return;
    }
    for (i = 0; i < 8 && (&D_001D4C80)[i] != 0; i++) {
    }
    if (i < 8) {
        (&D_001D4C80)[i] = id;
    }
}
