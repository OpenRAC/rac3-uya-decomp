#include "common.h"
typedef struct { u8 pad[0x30]; s32 x30; } O_329180;
extern s32 func_00328B90(s32);
extern s32 func_00328C78(s32);
extern void func_003290D8(s32, O_329180 *);
void func_00329180(s32 x, O_329180 *o) {
    if (o->x30 != 0 && func_00328B90(o->x30) && func_00328C78(o->x30)) {
        func_003290D8(x, o);
    }
}
