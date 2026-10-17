#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;

extern s32 D_001D94F8;
extern s32 D_001D94FC;
extern Ent_0049AB20 D_002EC7A8[];
extern s32 func_004181A0(s32);
extern s32 func_00512FE8(s32, s32);
extern void func_005131A0(s32, s32);
extern void func_00512D70(s32, s32);

void func_0049AB20(void)
{
    if (D_001D94F8 >= 0) {
        func_00512FE8(0x500008, func_004181A0(D_002EC7A8[D_001D94F8].f4));
        func_005131A0(0x500003, D_002EC7A8[D_001D94F8].f8 + 1);
        func_00512D70(D_001D94FC, 1);
    }
}
