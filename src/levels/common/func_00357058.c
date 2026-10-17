#include "common.h"

extern int func_00436340(u8 *);
extern void func_00350C38(u8 *, u8 *, int, int, int);
extern int func_00351B10(u8 *, u8 *);
extern void func_00425278(u8 *, int, int);

int func_00357058(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    if (func_00436340(moby)) {
        func_00350C38(moby, vars, 15, 0, 10);
        *(int *)(vars + 816) = 20;
    }
    func_00351B10(moby, vars);
    if (*(int *)(vars + 860) == 0) {
        func_00425278(moby, 27, -1);
        func_00350C38(moby, vars, 14, 0, 10);
        *(int *)(vars + 816) = 30;
        return 1;
    }
    return 0;
}
