#include "common.h"

typedef struct {
    s32 pad0[3];
    s32 xC;
} Entry_0048F958;

extern s32 D_001D8E98;
extern s32 D_001D8E9C;
extern s32 D_001D8EAC;
extern Entry_0048F958 D_002EB4E8[];
extern s32 func_00494DD0(s32);
extern s32 func_00494E58(s32);
extern void func_00512D70(s32, s32);
extern void func_005131A0(s32, s32);

void func_0048F958(void)
{
    s32 v;

    v = func_00494E58(func_00494DD0(0));
    D_001D8E98 = v;
    if (v < 0) {
        return;
    }
    if (D_001D8E9C != v) {
        D_001D8EAC = 30;
    }
    if (D_001D8EAC != 0) {
        if (--D_001D8EAC == 0) {
            func_00512D70(0x1C0003, 1);
            func_005131A0(0x1C0003, D_002EB4E8[D_001D8E98].xC);
        }
    }
    D_001D8E9C = D_001D8E98;
}
