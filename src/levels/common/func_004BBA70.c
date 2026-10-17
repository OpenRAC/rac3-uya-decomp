#include "common.h"

typedef struct {
    s32 id;
    s32 pad[3];
    u8 flag;
    u8 pad2[3];
} Ent_004BBA70;

typedef struct {
    u8 pad[320];
    Ent_004BBA70 ents[76];
    u8 pad2[16];
    s32 count;
} Tbl_004BBA70;

extern Tbl_004BBA70 D_00244740;

void func_004BBA70(s32 id) {
    s32 i;

    for (i = 0; i < D_00244740.count; i++) {
        if (D_00244740.ents[i].id == id) {
            D_00244740.ents[i].flag = 1;
        }
    }
}
