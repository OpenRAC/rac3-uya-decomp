#include "common.h"
typedef struct { u8 pad0[48]; s32 id; u8 pad1[28]; } Ent_00312A80;
extern Ent_00312A80 *D_001E17B0;
extern void func_00313290(Ent_00312A80 *);
void func_00312A80(s32 id) {
    s32 i;
    for (i = 0; i < 1; i++) {
        if (D_001E17B0[i].id == id) func_00313290(&D_001E17B0[i]);
    }
}
