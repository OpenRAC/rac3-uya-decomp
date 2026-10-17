#include "common.h"
typedef struct {
    s32 id;
    u8 pad[12];
} E_005E1A90;
extern u8 D_001D8310[8];
extern E_005E1A90 D_0049A1B8[];
extern s32 func_0060F870(void);
extern void func_0060E900(s32, s32, s32);
void func_005E1A90(void) {
    s32 i;
    D_001D8310[func_0060F870()] = 1;
    for (i = 0; i < 6; i++) {
        if ((u32)(D_0049A1B8[i].id - 0xD0013) < 3) {
            func_0060E900(D_0049A1B8[i].id, 1, 1);
        } else {
            func_0060E900(D_0049A1B8[i].id, 1, 0);
        }
    }
    func_0060E900(0xD0028, 1, 0);
}
