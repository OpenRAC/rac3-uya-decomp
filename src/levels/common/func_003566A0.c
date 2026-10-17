#include "common.h"

extern int func_00436340(u8 *);
extern void func_00350C38(u8 *, u8 *, int, int, int);
extern int func_003502D8(u8 *, u8 *, u8 *);
extern void func_00425278(u8 *, int, int);

int func_003566A0(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    if (func_00436340(moby)) {
        func_00350C38(moby, vars, 9, 0, 10);
    }
    func_003502D8(moby, vars, vars + 544);
    if (moby[96] & 2) {
        *(int *)(vars + 900) = 1;
        func_00425278(moby, 3, -1);
        func_00350C38(moby, vars, 10, 0, 10);
        return 1;
    }
    return 0;
}
