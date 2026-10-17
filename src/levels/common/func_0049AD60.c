#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;

extern S_2EC7A8 D_002EC7A8[];
extern s32 D_001D94F8;
extern s32 D_001D94F4;
extern s32 D_001D9504;
extern void func_005131A0(s32, s32);

void func_0049AD60(void) {
    S_2EC7A8 *p;
    s32 cont;

    p = &D_002EC7A8[D_001D94F8];
    cont = 1;
    do {
        p++;
        if (p->f0 == 0) {
            cont = 0;
        } else if (p->f14 != 0 || D_001D94F4 != 0) {
            cont = 0;
            func_005131A0(D_001D9504, p->f8 + 1);
        }
    } while (cont);
}
