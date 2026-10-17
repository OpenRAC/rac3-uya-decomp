#include "common.h"

typedef struct {
    u8 pad[1120];
} Ent1120;
extern Ent1120 D_001E28C0[];

void func_003FBBB8(s32 i) {
    u8 *e = (u8 *)&D_001E28C0[i];
    (*(u8 **)(e + 80))[136] = 1;
}
