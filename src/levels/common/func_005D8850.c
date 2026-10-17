#include "common.h"

extern unsigned char D_001D7F40[8];
extern int D_001D7F48[2];
extern unsigned char D_001D7F18[8];
extern int D_001D7F20[2];
extern int D_001D7F30[2];
extern char D_002B5880[][24];
extern char D_00243878[];
extern char D_00243880[];
extern int func_00120048(char *, char *, ...);

void func_005D8850(int a, int b, int idx)
{
    if (D_001D7F40[idx])
        D_001D7F48[idx] = 0;
    D_001D7F40[idx] = 0;
    if (D_001D7F18[idx]) {
        D_001D7F20[idx] = a;
        D_001D7F30[idx] = b;
    }
    if (a == 0 && b == 0)
        func_00120048(D_002B5880[idx], D_00243878);
    else
        func_00120048(D_002B5880[idx], D_00243880, a, b);
}
