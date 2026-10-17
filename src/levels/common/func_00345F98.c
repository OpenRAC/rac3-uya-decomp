#include "common.h"

extern s32 D_001DCF8C;
extern s32 D_001DCF84;
extern f32 D_001DCF80;
extern u8 D_001E11A8[];

extern int func_00423180(u8 *);
extern void func_00475240(int, int, u8 *, int);
extern void func_0034BC88(u8 *, void *, int, int, int, int, f32, f32);
extern void func_0034B9C8(void *, u8 *);
extern int func_003DF4F8(void *);
extern void func_00408760(u8 *);

void func_00345F98(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    if (func_00423180(moby)) {
        *(s32 *)(vars + 164) = D_001DCF8C;
        func_00475240(29, 0, moby, 4963);
    }
    func_0034BC88(moby, vars + 144, 0, -1, 0, 0, (f32)D_001DCF84, D_001DCF80);
    func_0034B9C8(D_001E11A8, moby);
    if (func_003DF4F8(vars + 164)) {
        func_00408760(moby);
    }
}
