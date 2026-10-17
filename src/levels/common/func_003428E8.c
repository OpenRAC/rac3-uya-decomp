#include "common.h"

extern u8 D_001A4C60[];

extern f32 func_003DFA18(void *, void *);
extern void func_00342810(u8 *);

void func_003428E8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    int saved;
    f32 d;
    if (vars[439]) {
        saved = *(int *)(vars + 404);
    }
    d = func_003DFA18(D_001A4C60, vars + 320);
    *(int *)(vars + 404) = func_003DFA18(D_001A4C60, vars + 336) < d;
    func_00342810(moby);
    if (vars[439]) {
        *(int *)(vars + 404) = saved;
    }
}
