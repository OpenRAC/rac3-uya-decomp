#include "common.h"

extern s32 func_0060F870(void);
extern void func_0060E900(s32, s32, s32);
extern u8 D_001D8310[8];

typedef struct {
    s32 id;
    s32 pad[3];
} Ent5E1B38;

extern Ent5E1B38 D_0049A1B8[];

void func_005E1B38(void) {
    s32 i;

    D_001D8310[func_0060F870()] = 0;
    for (i = 0; i < 6; i++) {
        if ((u32)(D_0049A1B8[i].id - 0xD0013) < 3) {
            func_0060E900(D_0049A1B8[i].id, 1, 0);
        } else {
            func_0060E900(D_0049A1B8[i].id, 1, 1);
        }
    }
    func_0060E900(0xD0028, 1, 1);
}
